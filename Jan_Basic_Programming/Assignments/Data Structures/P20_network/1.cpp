#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class MaxBipartiteMatching {
private:
    int n;
    vector<vector<int>> graph;
    vector<int> match;
    vector<bool> visited;

    bool bfs(int start, int target) {
        fill(visited.begin(), visited.end(), false);

        queue<int> q;
        q.push(start);
        visited[start] = true;
        match[start] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; ++v) {
                if (!visited[v] && graph[u][v] > 0) {
                    q.push(v);
                    match[v] = u;
                    visited[v] = true;

                    if (v == target) {
                        return true; 
                    }
                }
            }
        }

        return false; 
    }

    int fordFulkerson(int source, int target) {
        int maxMatching = 0;

        while (bfs(source, target)) {
            int pathFlow = INT_MAX;

            for (int v = target; v != source; v = match[v]) {
                int u = match[v];
                pathFlow = min(pathFlow, graph[u][v]);
            }

            for (int v = target; v != source; v = match[v]) {
                int u = match[v];
                graph[u][v] -= pathFlow;
                graph[v][u] += pathFlow;
            }

            maxMatching += pathFlow;
        }

        return maxMatching;
    }

public:
    MaxBipartiteMatching(int nodes) : n(nodes), graph(nodes, vector<int>(nodes)), match(nodes), visited(nodes) {}

    void addEdge(int u, int v) {
        graph[u][v] = 1; 
    }

    int findMaxMatching() {
        return fordFulkerson(0, n - 1); 
    }
};

int main() {
    
    MaxBipartiteMatching maxMatching(4);

    maxMatching.addEdge(0, 1);
    maxMatching.addEdge(0, 2);
    maxMatching.addEdge(1, 2);
    maxMatching.addEdge(2, 3);

    int result = maxMatching.findMaxMatching();
    cout << "Maximum Bipartite Matching: " << result << endl;

    return 0;
}
