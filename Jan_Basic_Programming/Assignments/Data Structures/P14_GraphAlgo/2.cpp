#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;
    vector<int> discovery;
    vector<int> low;
    vector<bool> visited;
    vector<bool> isArticulationPoint;
    int time;

public:
    Graph(int v) : vertices(v), adjList(v), discovery(v, -1), low(v, -1), visited(v, false), isArticulationPoint(v, false), time(0) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfs(int vertex, int parent) {
        int children = 0;
        visited[vertex] = true;
        discovery[vertex] = low[vertex] = ++time;

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                children++;
                dfs(neighbor, vertex);

                low[vertex] = min(low[vertex], low[neighbor]);

                if (low[neighbor] >= discovery[vertex] && parent != -1) {
                    isArticulationPoint[vertex] = true;
                }
            } else if (neighbor != parent) {
                low[vertex] = min(low[vertex], discovery[neighbor]);
            }
        }

        if (parent == -1 && children > 1) {
            isArticulationPoint[vertex] = true;
        }
    }

    void findArticulationPoints() {
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }

        cout << "Articulation Points:\n";
        for (int i = 0; i < vertices; ++i) {
            if (isArticulationPoint[i]) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    int vertices = 7;
    Graph graph(vertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);

    graph.findArticulationPoints();

    return 0;
}
