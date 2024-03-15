#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class HopcroftKarp {
private:
    vector<vector<int>> graph;
    vector<int> leftMatching, rightMatching, dist;

    bool bfs() {
        queue<int> q;
        dist.assign(leftMatching.size(), numeric_limits<int>::max());

        for (int i = 0; i < leftMatching.size(); ++i) {
            if (leftMatching[i] == -1) {
                dist[i] = 0;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] < dist.size()) {
                for (int v : graph[u]) {
                    if (rightMatching[v] == -1) {
                        return true; 
                    }

                    if (dist[rightMatching[v]] == numeric_limits<int>::max()) {
                        dist[rightMatching[v]] = dist[u] + 1;
                        q.push(rightMatching[v]);
                    }
                }
            }
        }

        return false; 
    }

    bool dfs(int u) {
        if (u != -1) {
            for (int v : graph[u]) {
                if (dist[rightMatching[v]] == dist[u] + 1 && dfs(rightMatching[v])) {
                    rightMatching[v] = u;
                    leftMatching[u] = v;
                    return true;
                }
            }

            dist[u] = numeric_limits<int>::max();
            return false;
        }

        return true;
    }

public:
    HopcroftKarp(int leftSize, int rightSize) {
        graph.resize(leftSize);
        leftMatching.assign(leftSize, -1);
        rightMatching.assign(rightSize, -1);
    }

    void addEdge(int left, int right) {
        graph[left].push_back(right);
    }

    int maximumMatching() {
        int matching = 0;
        while (bfs()) {
            for (int i = 0; i < leftMatching.size(); ++i) {
                if (leftMatching[i] == -1 && dfs(i)) {
                    matching++;
                }
            }
        }
        return matching;
    }
};

int main() {
    
    HopcroftKarp hopcroftKarp(4, 4);

    
    hopcroftKarp.addEdge(0, 1);
    hopcroftKarp.addEdge(0, 2);
    hopcroftKarp.addEdge(1, 2);
    hopcroftKarp.addEdge(2, 0);
    hopcroftKarp.addEdge(2, 3);
    hopcroftKarp.addEdge(3, 3);

    int maxMatching = hopcroftKarp.maximumMatching();
    cout << "Maximum Cardinality Matching: " << maxMatching << endl;

    return 0;
}
