#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> g;

    void addEdge(int u, int v, int weight)
    {
        g[u].push_back({v, weight});
        g[v].push_back({u, weight});
    }

    void printGraph()
    {
        for (auto i : g)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << ") ";
            }
            cout << endl;
        }
    }

    void primMST()
    {
        int V = g.size();
        vector<bool> isInMST(V, false);
        vector<int> parent(V, -1);
        vector<int> distance(V, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int startVertex = 0; // Choose any starting vertex
        pq.push({0, startVertex});
        distance[startVertex] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            isInMST[u] = true;

            for (auto neighbor : g[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!isInMST[v] && weight < distance[v])
                {
                    distance[v] = weight;
                    parent[v] = u;
                    pq.push({distance[v], v});
                }
            }
        }

        // Print MST edges
        cout << "Minimum Spanning Tree Edges:" << endl;
        for (int i = 1; i < V; ++i)
        {
            cout << parent[i] << " - " << i << " Weight: " << distance[i] << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 1, 4);
    g.addEdge(3, 4, 5);
    g.addEdge(0, 4, 6);

    g.printGraph();

    cout << "\nPrim's Algorithm:" << endl;
    g.primMST();

    return 0;
}
