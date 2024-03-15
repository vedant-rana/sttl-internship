#include <iostream>
#include <vector>

class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    Graph(int V) : vertices(V), adjacencyMatrix(V, std::vector<int>(V, 0)) {}

    void addEdge(int u, int v) {
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;
    }

    void eulerianCircuitUtil(int v, std::vector<int>& circuit);

    void printEulerianCircuit();
};

void Graph::eulerianCircuitUtil(int v, std::vector<int>& circuit) {
    for (int u = 0; u < vertices; u++) {
        if (adjacencyMatrix[v][u]) {
            circuit.push_back(u);
            adjacencyMatrix[v][u] = 0;
            adjacencyMatrix[u][v] = 0;

            eulerianCircuitUtil(u, circuit);
        }
    }
}

void Graph::printEulerianCircuit() {
    std::vector<int> circuit;
    circuit.push_back(0);  

    eulerianCircuitUtil(0, circuit);

    std::cout << "Eulerian Circuit: ";
    for (int vertex : circuit) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 0);
    g.addEdge(3, 3);

    g.printEulerianCircuit();

    return 0;
}
