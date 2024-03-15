#include <iostream>
#include <vector>
#include <unordered_set>

int maximalNetworkRank(int n, std::vector<std::vector<int>> &roads)
{

    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    std::vector<std::unordered_set<int>> neighbors(n);

    for (const auto &road : roads)
    {
        int city1 = road[0];
        int city2 = road[1];

        graph[city1][city2] = 1;
        graph[city2][city1] = 1;

        neighbors[city1].insert(city2);
        neighbors[city2].insert(city1);
    }

    int maxRank = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int rank = neighbors[i].size() + neighbors[j].size();

            if (graph[i][j] == 1 || graph[j][i] == 1)
            {
                rank -= 1;
            }

            maxRank = std::max(maxRank, rank);
        }
    }

    return maxRank;
}

int main()
{

    int n = 5;
    std::vector<std::vector<int>> roads = {{0, 1}, {0, 3}, {1, 2}, {1, 4}};

    int result = maximalNetworkRank(n, roads);

    std::cout << "Maximal Network Rank: " << result << std::endl;

    return 0;
}
