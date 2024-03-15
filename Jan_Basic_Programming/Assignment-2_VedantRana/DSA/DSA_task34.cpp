#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adjacencyList;

public:
    Graph(int V) : vertices(V), adjacencyList(V) {}

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
    }

    void topologicalSortUtil(int v, std::vector<bool>& visited, std::stack<int>& result) {
        visited[v] = true;

        for (int neighbor : adjacencyList[v]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, visited, result);
            }
        }

        result.push(v);
    }

    void topologicalSort() {
        std::stack<int> result;
        std::vector<bool> visited(vertices, false);

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, result);
            }
        }

        std::cout << "Topological Sorting: ";
        while (!result.empty()) {
            std::cout << result.top() << " ";
            result.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;
}
