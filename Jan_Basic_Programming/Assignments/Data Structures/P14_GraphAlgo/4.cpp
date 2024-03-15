#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class FordFulkerson {
private:
    int vertices;
    vector<vector<int>> capacity;
    vector<vector<int>> residualCapacity;
    vector<vector<int>> flow;
    
    int min(int a, int b) {
        return (a < b) ? a : b;
    }

public:
    FordFulkerson(int v) : vertices(v), capacity(v, vector<int>(v, 0)), residualCapacity(v, vector<int>(v, 0)), flow(v, vector<int>(v, 0)) {}

    void addEdge(int u, int v, int cap) {
        capacity[u][v] += cap; 
        capacity[v][u] += cap;  
    }

    int fordFulkerson(int source, int sink) {
        int maxFlow = 0;

        while (true) {
            vector<int> parent(vertices, -1);
            queue<pair<int, int>> bfsQueue;

            bfsQueue.push({source, INT_MAX});
            parent[source] = source;

            while (!bfsQueue.empty()) {
                int current = bfsQueue.front().first;
                int minCapacity = bfsQueue.front().second;
                bfsQueue.pop();

                for (int neighbor = 0; neighbor < vertices; ++neighbor) {
                    if (parent[neighbor] == -1 && residualCapacity[current][neighbor] > 0) {
                        parent[neighbor] = current;
                        int newMinCapacity = min(minCapacity, residualCapacity[current][neighbor]);
                        bfsQueue.push({neighbor, newMinCapacity});

                        if (neighbor == sink) {
                            int pathFlow = newMinCapacity;
                            int u = sink;

                            while (u != source) {
                                int v = parent[u];
                                flow[v][u] += pathFlow;
                                flow[u][v] -= pathFlow;
                                residualCapacity[v][u] += pathFlow;
                                residualCapacity[u][v] -= pathFlow;
                                u = v;
                            }

                            maxFlow += pathFlow;
                            break;
                        }
                    }
                }
            }

            if (parent[sink] == -1) {
                break;
            }
        }

        return maxFlow;
    }
};

int main() {
    int vertices = 6;
    FordFulkerson fordFulkerson(vertices);


    fordFulkerson.addEdge(0, 1, 16);
    fordFulkerson.addEdge(0, 2, 13);
    fordFulkerson.addEdge(1, 2, 10);
    fordFulkerson.addEdge(1, 3, 12);
    fordFulkerson.addEdge(2, 1, 4);
    fordFulkerson.addEdge(2, 4, 14);
    fordFulkerson.addEdge(3, 2, 9);
    fordFulkerson.addEdge(3, 5, 20);
    fordFulkerson.addEdge(4, 3, 7);
    fordFulkerson.addEdge(4, 5, 4);

    int source = 0, sink = 5;
    int maxFlow = fordFulkerson.fordFulkerson(source, sink);

    cout << "Maximum Flow from source " << source << " to sink " << sink << ": " << maxFlow << endl;

    return 0;
}
