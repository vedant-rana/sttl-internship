#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
private:
    unordered_map<int, unordered_set<int>> adjacencyList;

public:
    void addVertex(int vertex) {
        if (adjacencyList.find(vertex) == adjacencyList.end()) {
            adjacencyList[vertex] = unordered_set<int>();
            cout << "Vertex " << vertex << " added." << endl;
        } else {
            cout << "Vertex " << vertex << " already exists." << endl;
        }
    }

    void removeVertex(int vertex) {
        if (adjacencyList.find(vertex) != adjacencyList.end()) {
            adjacencyList.erase(vertex);
            for (auto& pair : adjacencyList) {
                pair.second.erase(vertex);
            }
            cout << "Vertex " << vertex << " removed." << endl;
        } else {
            cout << "Vertex " << vertex << " does not exist." << endl;
        }
    }

    void addEdge(int from, int to) {
        if (adjacencyList.find(from) != adjacencyList.end() && adjacencyList.find(to) != adjacencyList.end()) {
            
            adjacencyList[from].insert(to);
            cout << "Edge (" << from << " -> " << to << ") added." << endl;
        } else {
            cout << "One or both of the vertices do not exist." << endl;
        }
    }

    void removeEdge(int from, int to) {
        if (adjacencyList.find(from) != adjacencyList.end() && adjacencyList[from].find(to) != adjacencyList[from].end()) {
           
            adjacencyList[from].erase(to);
            cout << "Edge (" << from << " -> " << to << ") removed." << endl;
        } else {
            cout << "Edge (" << from << " -> " << to << ") does not exist." << endl;
        }
    }

    void printGraph() {
        cout << "Graph representation:" << endl;
        for (const auto& pair : adjacencyList) {
            cout << pair.first << " -> ";
            for (int neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph;


    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);


    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    
    graph.printGraph();


    graph.removeEdge(1, 2);
    graph.removeVertex(2);


    graph.printGraph();

    return 0;
}
