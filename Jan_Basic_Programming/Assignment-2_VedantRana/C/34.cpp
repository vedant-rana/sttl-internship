#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class BipartiteMatching
{
private:
    int leftSize;
    int rightSize;
    vector<vector<int>> graph;
    vector<int> matchLeft;
    vector<int> matchRight;
    vector<int> dist;

    bool bfs()
    {
        queue<int> q;

        for (int u = 1; u <= leftSize; ++u)
        {
            if (matchLeft[u] == 0)
            {
                dist[u] = 0;
                q.push(u);
            }
            else
            {
                dist[u] = numeric_limits<int>::max();
            }
        }

        dist[0] = numeric_limits<int>::max();

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (dist[u] < dist[0])
            {
                for (int v : graph[u])
                {
                    if (dist[matchRight[v]] == numeric_limits<int>::max())
                    {
                        dist[matchRight[v]] = dist[u] + 1;
                        q.push(matchRight[v]);
                    }
                }
            }
        }

        return (dist[0] != numeric_limits<int>::max());
    }

    bool dfs(int u)
    {
        if (u != 0)
        {
            for (int v : graph[u])
            {
                if (dist[matchRight[v]] == dist[u] + 1 && dfs(matchRight[v]))
                {
                    matchLeft[u] = v;
                    matchRight[v] = u;
                    return true;
                }
            }

            dist[u] = numeric_limits<int>::max();
            return false;
        }

        return true;
    }

public:
    BipartiteMatching(int left, int right) : leftSize(left), rightSize(right)
    {
        graph.resize(left + 1);
        matchLeft.resize(left + 1, 0);
        matchRight.resize(right + 1, 0);
        dist.resize(left + 1);
    }

    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
    }

    int hopcroftKarp()
    {
        int matching = 0;

        while (bfs())
        {
            for (int u = 1; u <= leftSize; ++u)
            {
                if (matchLeft[u] == 0 && dfs(u))
                {
                    matching++;
                }
            }
        }

        return matching;
    }
};

int main()
{

    int leftSize = 3;
    int rightSize = 4;

    BipartiteMatching bipartiteMatching(leftSize, rightSize);

    bipartiteMatching.addEdge(1, 1);
    bipartiteMatching.addEdge(1, 2);
    bipartiteMatching.addEdge(2, 2);
    bipartiteMatching.addEdge(2, 3);
    bipartiteMatching.addEdge(3, 3);
    bipartiteMatching.addEdge(3, 4);

    int maxMatching = bipartiteMatching.hopcroftKarp();

    cout << "Maximum Bipartite Matching: " << maxMatching << endl;

    return 0;
}
