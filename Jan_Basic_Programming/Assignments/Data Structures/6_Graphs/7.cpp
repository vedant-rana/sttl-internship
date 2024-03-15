#include <iostream>
#include <vector>
#include <queue>

class Graph {
public:
    int vertices;
    std::vector<std::vector<int>> adjList;

    Graph(int v) : vertices(v), adjList(v) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    bool isBipartite() {
        std::vector<int> color(vertices, -1);
        std::queue<int> q;

        for (int startNode = 0; startNode < vertices; ++startNode) {
            if (color[startNode] == -1) {
                color[startNode] = 0; 
                q.push(startNode);

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : adjList[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u]; 
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Graph g(4); 


    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    if (g.isBipartite()) {
        std::cout << "Graph is bipartite.\n";
    } else {
        std::cout << "Graph is not bipartite.\n";
    }

    return 0;
}
