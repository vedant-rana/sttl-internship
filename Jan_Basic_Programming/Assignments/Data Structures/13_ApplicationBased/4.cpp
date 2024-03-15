#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

bool isValid(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

int shortestPathInMaze(vector<vector<int>>& maze, Point start, Point end) {
    int rows = maze.size();
    int cols = maze[0].size();

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    queue<pair<Point, int>> bfsQueue;
    bfsQueue.push({start, 0});
    visited[start.x][start.y] = true;

    while (!bfsQueue.empty()) {
        Point current = bfsQueue.front().first;
        int distance = bfsQueue.front().second;
        bfsQueue.pop();

        if (current.x == end.x && current.y == end.y) {
            return distance;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValid(newX, newY, rows, cols) && maze[newX][newY] == 0 && !visited[newX][newY]) {
                bfsQueue.push({{newX, newY}, distance + 1});
                visited[newX][newY] = true;
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };

    Point start = {0, 0};
    Point end = {4, 4};

    int shortestPath = shortestPathInMaze(maze, start, end);

    if (shortestPath != -1) {
        cout << "Shortest path length: " << shortestPath << endl;
    } else {
        cout << "No path found to the destination." << endl;
    }

    return 0;
}
