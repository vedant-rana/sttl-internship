#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Graph {
private:
    int vertices;
    std::unordered_map<int, std::vector<int>> adjList;

public:
    Graph(int V) : vertices(V) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool isConnected() const {
        std::vector<bool> visited(vertices, false);
        int startVertex = -1;

        
        for (auto it = adjList.begin(); it != adjList.end(); it++) {
            if (!it->second.empty()) {
                startVertex = it->first;
                break;
            }
        }

        if (startVertex == -1) {
            
            return true;
        }

        
        dfs(startVertex, visited);

        
        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && adjList[i].size() > 0) {
                return false;
            }
        }

        return true;
    }

    int countOddDegreeVertices() const {
        int count = 0;
        for (auto it = adjList.begin(); it != adjList.end(); it++) {
            if (it->second.size() % 2 != 0) {
                count++;
            }
        }
        return count;
    }

    bool hasEulerianPath() const {
        if (!isConnected()) {
            return false;
        }

        int oddDegreeCount = countOddDegreeVertices();

        
        return oddDegreeCount == 0 || oddDegreeCount == 2;
    }

    bool hasEulerianCircuit() const {
        if (!isConnected()) {
            return false;
        }

        
        for (auto it = adjList.begin(); it != adjList.end(); it++) {
            if (it->second.size() % 2 != 0) {
                return false;
            }
        }

        return true;
    }

private:
    void dfs(int vertex, std::vector<bool>& visited) const {
        visited[vertex] = true;
        for (int neighbor : adjList.at(vertex)) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }
};

int main() {
    Graph graph(5);

    
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);

    
    if (graph.hasEulerianPath()) {
        std::cout << "The graph has an Eulerian Path.\n";
    } else if (graph.hasEulerianCircuit()) {
        std::cout << "The graph has an Eulerian Circuit.\n";
    } else {
        std::cout << "The graph doesn't have an Eulerian Path or Circuit.\n";
    }

    return 0;
}
