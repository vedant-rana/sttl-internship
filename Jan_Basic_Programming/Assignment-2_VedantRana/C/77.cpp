#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> sumOfDistancesInTree(int N, std::vector<std::vector<int>> &edges)
    {
        graph.resize(N);
        count.resize(N, 1);
        result.resize(N, 0);

        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        postOrder(0, -1);
        preOrder(0, -1);

        return result;
    }

private:
    std::vector<std::vector<int>> graph;
    std::vector<int> count;
    std::vector<int> result;

    void postOrder(int node, int parent)
    {
        for (int child : graph[node])
        {
            if (child != parent)
            {
                postOrder(child, node);
                count[node] += count[child];
                result[node] += result[child] + count[child];
            }
        }
    }

    void preOrder(int node, int parent)
    {
        for (int child : graph[node])
        {
            if (child != parent)
            {
                result[child] = result[node] - count[child] + graph.size() - count[child];
                preOrder(child, node);
            }
        }
    }
};

int main()
{
    Solution solution;

    int N = 6;
    std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};

    std::vector<int> result = solution.sumOfDistancesInTree(N, edges);

    std::cout << "Sum of Distances in Tree: ";
    for (int val : result)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
