#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Graph
{
public:
    int vertices;
    vector<vector<int>> adjList;

    Graph(int v) : vertices(v), adjList(v) {}

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void DFS(int v, unordered_set<int> &visited, vector<int> &component)
    {
        visited.insert(v);
        component.push_back(v);

        for (int neighbor : adjList[v])
        {
            if (visited.find(neighbor) == visited.end())
            {
                DFS(neighbor, visited, component);
            }
        }
    }

    void findConnectedComponents()
    {
        unordered_set<int> visited;

        for (int v = 0; v < vertices; ++v)
        {
            if (visited.find(v) == visited.end())
            {
                vector<int> component;
                DFS(v, visited, component);

                cout << "Connected Component: ";
                for (int node : component)
                {
                    cout << node << " ";
                }
                cout << "\n";
            }
        }
    }
};

int main()
{
    Graph g(9);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 8);

    g.findConnectedComponents();

    return 0;
}
