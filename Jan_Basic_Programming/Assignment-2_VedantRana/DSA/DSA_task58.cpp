#include <iostream>
#include <vector>
#include <queue>
#include <numeric> 
#include <cstring>

using namespace std;

const int INF = 1e9;

class Blossom {
public:
    Blossom(int n) : n(n), match(n, -1), base(n), blossom(n), label(n), parent(n) {}

    void addEdge(int u, int v) {
        graph[u][v] = graph[v][u] = 1;
    }

    int findMaxMatching() {
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (match[i] == -1) {
                result += augment(i);
            }
        }
        return result;
    }

private:
    int findCommonAncestor(int u, int v) {
        memset(label.data(), 0, sizeof(int) * n);
        while (true) {
            u = base[u];
            label[u] = 1;
            if (match[u] == -1) break;
            u = parent[match[u]];
        }

        while (true) {
            v = base[v];
            if (label[v]) return v;
            v = parent[match[v]];
        }
    }

    void blossomContract(int u, int v, int a) {
        int ancestor = findCommonAncestor(u, v);
        memset(blossom.data(), 0, sizeof(int) * n);
        markBlossom(u, ancestor, v);
        markBlossom(v, ancestor, u);

        if (base[u] == -1) base[u] = a;
        if (base[v] == -1) base[v] = a;
        
        for (int i = 0; i < n; i++) {
            if (blossom[i]) {
                base[i] = a;
                if (!label[i]) {
                    label[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    void markBlossom(int start, int ancestor, int end) {
        while (base[start] != ancestor) {
            blossom[base[start]] = blossom[base[parent[match[start]]]] = 1;
            parent[start] = end;
            end = match[start];
            start = parent[match[start]];
        }
    }

    int augment(int start) {
        fill(parent.begin(), parent.end(), -1);
        fill(label.begin(), label.end(), 0);
        iota(base.begin(), base.end(), 0); 
        while (!q.empty()) q.pop();

        label[start] = 1;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; v++) {
                if (!graph[u][v]) continue;

                if (base[u] != base[v] && match[u] != v) {
                    if ((v == start) || (match[v] != -1 && parent[match[v]] != -1)) {
                        int a = findCommonAncestor(base[u], base[v]);
                        blossomContract(u, v, a);
                    } else if (parent[v] == -1) {
                        parent[v] = u;
                        if (match[v] == -1) {
                            return augmentPath(v);
                        } else {
                            label[match[v]] = 1;
                            q.push(match[v]);
                        }
                    }
                }
            }
        }

        return 0;
    }

    int augmentPath(int v) {
        while (v != -1) {
            int pv = parent[v];
            int ppv = match[pv];
            match[v] = pv;
            match[pv] = v;
            v = ppv;
        }
        return 1;
    }

private:
    int n;
    vector<vector<int>> graph;
    vector<int> match, base, blossom, label, parent;
    queue<int> q;
};

int main() {
    int n = 6; 
    Blossom blossom(n);

    
    blossom.addEdge(0, 1);
    blossom.addEdge(0, 2);
    blossom.addEdge(1, 3);
    blossom.addEdge(3, 4);
    blossom.addEdge(4, 5);
    blossom.addEdge(5, 3);

    int maxMatching = blossom.findMaxMatching();
    cout << "Maximum Cardinality Matching: " << maxMatching << endl;

    return 0;
}
