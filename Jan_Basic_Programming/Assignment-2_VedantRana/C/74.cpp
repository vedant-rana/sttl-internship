#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

class TarjanDominators
{
public:
    TarjanDominators(int vertices) : n(vertices)
    {
        adj.resize(n);
        dom.resize(n);
        parent.resize(n, -1);
        ancestor.resize(n, -1);
        label.resize(n);
        semi.resize(n);
        idom.resize(n, -1);
        bucket.resize(n);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void runTarjan(int startNode)
    {
        index = 0;
        dfs(startNode);
        computeDominators(startNode);
    }

    int getDominators(int node) const
    {
        return idom[node];
    }

private:
    int n;
    int index;
    std::vector<std::vector<int>> adj;
    std::vector<int> dom;
    std::vector<int> parent;
    std::vector<int> ancestor;
    std::vector<int> label;
    std::vector<int> semi;
    std::vector<int> idom;
    std::vector<std::vector<int>> bucket;

    void dfs(int v)
    {
        label[v] = index;
        semi[v] = index;
        index++;

        for (int u : adj[v])
        {
            if (label[u] == -1)
            {
                parent[u] = v;
                dfs(u);
            }
        }
    }

    int find(int v)
    {
        if (ancestor[v] == -1)
        {
            return v;
        }
        else
        {
            int root = find(ancestor[v]);
            if (label[semi[ancestor[v]]] < label[semi[v]])
            {
                semi[v] = semi[ancestor[v]];
            }
            ancestor[v] = root;
            return root;
        }
    }

    void link(int v, int w)
    {
        ancestor[w] = v;
    }

    void compress(int v)
    {
        std::stack<int> stk;
        stk.push(v);

        while (!stk.empty())
        {
            int w = stk.top();
            stk.pop();

            int u = find(w);
            dom[w] = (label[semi[u]] < label[semi[w]]) ? semi[u] : v;

            for (int x : bucket[w])
            {
                compress(x);
            }
            bucket[w].clear();
        }
    }

    void computeDominators(int startNode)
    {
        for (int i = index - 1; i >= 1; --i)
        {
            int w = label[i];
            for (int v : adj[w])
            {
                if (label[v] != -1)
                {
                    int u = find(v);
                    if (label[semi[u]] < label[semi[w]])
                    {
                        semi[w] = semi[u];
                    }
                }
            }

            bucket[semi[w]].push_back(w);
            link(parent[w], w);

            compress(parent[w]);

            for (int v : bucket[parent[w]])
            {
                int u = find(v);
                idom[v] = (semi[u] < semi[v]) ? u : parent[w];
            }
            bucket[parent[w]].clear();
        }

        for (int i = 1; i < index; ++i)
        {
            int w = label[i];
            if (idom[w] != semi[w])
            {
                idom[w] = idom[idom[w]];
            }
        }

        idom[startNode] = startNode;
    }
};

int main()
{

    int vertices = 5;
    TarjanDominators tarjan(vertices);

    tarjan.addEdge(0, 1);
    tarjan.addEdge(1, 2);
    tarjan.addEdge(2, 3);
    tarjan.addEdge(3, 4);
    tarjan.addEdge(4, 0);

    tarjan.runTarjan(0);

    for (int i = 0; i < vertices; ++i)
    {
        std::cout << "Dominators of node " << i << ": " << tarjan.getDominators(i) << std::endl;
    }

    return 0;
}
