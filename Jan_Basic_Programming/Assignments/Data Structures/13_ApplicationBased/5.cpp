#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Graph {
public:
    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool hasCycle() {
        unordered_set<int> visited;
        for (int i = 0; i < V; ++i) {
            if (visited.find(i) == visited.end()) {
                if (dfsHasCycle(i, -1, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    int V;
    vector<vector<int>> adjList;

    bool dfsHasCycle(int current, int parent, unordered_set<int>& visited) {
        visited.insert(current);

        for (int neighbor : adjList[current]) {
            if (visited.find(neighbor) == visited.end()) {
                if (dfsHasCycle(neighbor, current, visited)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);

    if (graph.hasCycle()) {
        cout << "The graph has a cycle.\n";
    } else {
        cout << "The graph does not have a cycle.\n";
    }

    return 0;
}
