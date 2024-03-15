#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct DisjointSet {
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int v) {
        if (v != parent[v])
            parent[v] = find(parent[v]);
        return parent[v];
    }

    void unionSets(int root1, int root2) {
        if (rank[root1] > rank[root2])
            parent[root2] = root1;
        else if (rank[root1] < rank[root2])
            parent[root1] = root2;
        else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

void kruskalMST(vector<Edge>& edges, int numVertices) {
    sort(edges.begin(), edges.end(), compareEdges);
    
    DisjointSet disjointSet(numVertices);

    cout << "Edges in the MST:\n";
    for (const Edge& edge : edges) {
        int root1 = disjointSet.find(edge.src);
        int root2 = disjointSet.find(edge.dest);

        if (root1 != root2) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << "\n";
            disjointSet.unionSets(root1, root2);
        }
    }
}

int main() {
    int numVertices = 4;
    vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    kruskalMST(edges, numVertices);

    return 0;
}
