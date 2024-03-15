#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_ROWS = 12;
const int MAX_COLS = 10;

bool isValid(int row, int col) {
    return row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS;
}

bool isSafe(vector<vector<int>>& grid, int row, int col) {
    return isValid(row, col) && grid[row][col] == 1;
}

int shortestSafeRoute(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> end) {
    vector<vector<bool>> visited(MAX_ROWS, vector<bool>(MAX_COLS, false));

    queue<pair<pair<int, int>, int>> q; 
    q.push({start, 0});
    visited[start.first][start.second] = true;

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 

    while (!q.empty()) {
        pair<pair<int, int>, int> current = q.front();
        q.pop();

        int currentRow = current.first.first;
        int currentCol = current.first.second;
        int currentDist = current.second;

        if (currentRow == end.first && currentCol == end.second) {
            return currentDist;
        }

        for (int i = 0; i < 4; ++i) {
            int newRow = currentRow + directions[i][0];
            int newCol = currentCol + directions[i][1];

            if (isSafe(grid, newRow, newCol) && !visited[newRow][newCol]) {
                q.push({{newRow, newCol}, currentDist + 1});
                visited[newRow][newCol] = true;
            }
        }
    }

    return -1; 
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> end = {11, 9};

    int result = shortestSafeRoute(grid, start, end);

    if (result != -1) {
        cout << "Shortest Safe Route Length: " << result << endl;
    } else {
        cout << "No Safe Route Found" << endl;
    }

    return 0;
}
