#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>

class Graph
{
public:
    Graph(int vertices) : V(vertices)
    {
        adjacencyList.resize(vertices);
    }

    void addEdge(int src, int dest)
    {
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src);
    }

    void parallelBFS(int startVertex)
    {
        std::vector<bool> visited(V, false);
        std::queue<int> bfsQueue;

        bfsQueue.push(startVertex);
        visited[startVertex] = true;

        while (!bfsQueue.empty())
        {
            int currentVertex = bfsQueue.front();
            bfsQueue.pop();

#pragma omp parallel for
            for (int i = 0; i < adjacencyList[currentVertex].size(); ++i)
            {
                int neighbor = adjacencyList[currentVertex][i];
                if (!visited[neighbor])
                {
#pragma omp critical
                    {
                        bfsQueue.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
    }

private:
    int V;
    std::vector<std::vector<int>> adjacencyList;
};

int main()
{

    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);

    int startVertex = 0;

    graph.parallelBFS(startVertex);

    std::cout << "Parallel BFS starting from vertex " << startVertex << " completed." << std::endl;

    return 0;
}
