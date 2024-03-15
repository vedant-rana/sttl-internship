#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

const int INF = INT_MAX;

class FordFulkerson
{
private:
    int numVertices; // Number of vertices in the graph
    vector<vector<int>> residualGraph;

public:
    FordFulkerson(int vertices) : numVertices(vertices)
    {
        // Initialize the residual graph with zero capacities
        residualGraph.resize(vertices, vector<int>(vertices, 0));
    }

    // Add an edge to the residual graph with a given capacity
    void addEdge(int from, int to, int capacity)
    {
        residualGraph[from][to] = capacity;
    }

    // Ford-Fulkerson algorithm using Edmonds-Karp variant with BFS
    int maxFlow(int source, int sink)
    {
        int maxFlow = 0;

        // While there exists an augmenting path in the residual graph
        while (true)
        {
            vector<int> parent(numVertices, -1);
            queue<pair<int, int>> bfsQueue;

            bfsQueue.push({source, INF});
            parent[source] = source;

            // BFS to find an augmenting path
            while (!bfsQueue.empty())
            {
                int current = bfsQueue.front().first;
                int minCapacity = bfsQueue.front().second;
                bfsQueue.pop();

                for (int neighbor = 0; neighbor < numVertices; ++neighbor)
                {
                    if (parent[neighbor] == -1 && residualGraph[current][neighbor] > 0)
                    {
                        int newMinCapacity = min(minCapacity, residualGraph[current][neighbor]);
                        parent[neighbor] = current;
                        if (neighbor == sink)
                        {
                            // Found an augmenting path
                            maxFlow += newMinCapacity;
                            augmentPath(parent, source, sink, newMinCapacity);
                            break;
                        }
                        bfsQueue.push({neighbor, newMinCapacity});
                    }
                }
            }

            // If no augmenting path is found, terminate the algorithm
            if (parent[sink] == -1)
            {
                break;
            }
        }

        return maxFlow;
    }

private:
    // Augment the flow along the augmenting path in the residual graph
    void augmentPath(const vector<int> &parent, int source, int sink, int minCapacity)
    {
        int current = sink;

        // Update the residual capacities along the augmenting path
        while (current != source)
        {
            int prev = parent[current];
            residualGraph[prev][current] -= minCapacity;
            residualGraph[current][prev] += minCapacity;
            current = prev;
        }
    }
};

int main()
{
    // Create a graph with 6 vertices
    FordFulkerson graph(6);

    // Add edges with capacities to the graph
    graph.addEdge(0, 1, 16);
    graph.addEdge(0, 2, 13);
    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 3, 12);
    graph.addEdge(2, 1, 4);
    graph.addEdge(2, 4, 14);
    graph.addEdge(3, 2, 9);
    graph.addEdge(3, 5, 20);
    graph.addEdge(4, 3, 7);
    graph.addEdge(4, 5, 4);

    // Compute and print the maximum flow from source (0) to sink (5)
    int source = 0;
    int sink = 5;
    int maxFlow = graph.maxFlow(source, sink);

    cout << "Maximum Flow from " << source << " to " << sink << ": " << maxFlow << endl;

    return 0;
}
