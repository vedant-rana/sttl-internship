#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> g;

    void addEdge(int u, int v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void printGraph()
    {
        for (auto i : g)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    void dfsPrint(int vertex)
    {
        unordered_map<int, bool> visited;
        dfs(vertex, visited);
    }

    void dfs(int vertex, unordered_map<int, bool> &visited)
    {
        visited[vertex] = true;
        cout << vertex << " ";

        for (auto neighbour : g[vertex])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(0, 4);

    g.printGraph();

    cout << "DFS : ";
    g.dfsPrint(0);
    return 0;
}