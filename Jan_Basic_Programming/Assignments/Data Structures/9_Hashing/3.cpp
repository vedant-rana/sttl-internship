#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
using namespace std;

class Graph {
public:
    Graph(int vertices) : vertices(vertices), adjList(vertices) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    bool isCyclic() {
        unordered_set<int> visited;

        for (int vertex = 0; vertex < vertices; ++vertex) {
            if (visited.find(vertex) == visited.end() && isCyclicUtil(vertex, -1, visited)) {
                return true;
            }
        }

        return false;
    }

private:
    int vertices;
    vector<vector<int>> adjList;

    bool isCyclicUtil(int vertex, int parent, unordered_set<int>& visited) {
        visited.insert(vertex);

        for (int neighbor : adjList[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                if (isCyclicUtil(neighbor, vertex, visited)) {
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
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    if (graph.isCyclic()) {
        cout << "The graph contains a cycle.\n";
    } else {
        cout << "The graph does not contain a cycle.\n";
    }

    return 0;
}
