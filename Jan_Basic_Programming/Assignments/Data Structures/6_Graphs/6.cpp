#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjList;

    Graph(int v) : vertices(v), adjList(v) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    bool isCyclicUtil(int v, vector<bool>& visited, unordered_set<int>& recursionStack) {
        visited[v] = true;
        recursionStack.insert(v);

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor, visited, recursionStack)) {
                    return true;
                }
            } else if (recursionStack.find(neighbor) != recursionStack.end()) {
                return true;
            }
        }

        recursionStack.erase(v);

        return false;
    }

    bool isCyclic() {
        vector<bool> visited(vertices, false);
        unordered_set<int> recursionStack;

        for (int v = 0; v < vertices; ++v) {
            if (!visited[v]) {
                if (isCyclicUtil(v, visited, recursionStack)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Graph g(4); 

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    if (g.isCyclic()) {
        cout << "Graph contains a cycle.\n";
    } else {
        cout << "Graph does not contain a cycle.\n";
    }

    return 0;
}
