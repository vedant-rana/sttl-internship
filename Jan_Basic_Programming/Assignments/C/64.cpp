#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> g; // pair: (destination, weight)

    void addEdge(int u, int v, int w)
    {
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    void printGraph()
    {
        for (auto i : g)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }

    vector<int> dijkstra(int start)
    {
        vector<int> distances(g.size(), numeric_limits<int>::max());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // pair<int, int> where first int = node and second int = distance

        distances[start] = 0;
        pq.push({0, start});

        while (!pq.empty())
        {
            int currentDistance = pq.top().first;
            int current = pq.top().second;
            pq.pop();

            if (currentDistance > distances[current])
            {
                continue;
            }

            for (auto neighbor : g[current])
            {
                int newDistance = currentDistance + neighbor.second;
                if (newDistance < distances[neighbor.first])
                {
                    distances[neighbor.first] = newDistance;
                    pq.push({newDistance, neighbor.first});
                }
            }
        }

        return distances;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 1, 7);
    g.addEdge(3, 4, 1);
    g.addEdge(0, 4, 4);

    g.printGraph();

    int startNode = 0;
    cout << "\nShortest distances from node " << startNode << " using Dijkstra's algorithm:\n";
    vector<int> shortestDistances = g.dijkstra(startNode);

    for (int i = 0; i < shortestDistances.size(); ++i)
    {
        cout << "To node " << i << ": ";
        if (shortestDistances[i] == numeric_limits<int>::max())
        {
            cout << "INF";
        }
        else
        {
            cout << shortestDistances[i];
        }
        cout << endl;
    }

    return 0;
}
