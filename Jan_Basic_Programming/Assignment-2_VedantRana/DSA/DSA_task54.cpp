#include <iostream>
#include <vector>

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    void printParentArray() {
        std::cout << "Parent Array: ";
        for (int i : parent) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

class PersistentUnionFind {
private:
    std::vector<UnionFind> snapshots;

public:
    PersistentUnionFind(int n) {
        snapshots.emplace_back(n);
    }

    void unionSets(int x, int y) {
        UnionFind latestSnapshot = snapshots.back();
        snapshots.emplace_back(latestSnapshot);
        snapshots.back().unionSets(x, y);
    }

    bool isConnected(int x, int y, int time) {
        if (time < 0 || time >= snapshots.size()) {
            std::cerr << "Invalid time value.\n";
            return false;
        }
        return snapshots[time].isConnected(x, y);
    }

    void printParentArray(int time) {
        if (time < 0 || time >= snapshots.size()) {
            std::cerr << "Invalid time value.\n";
            return;
        }
        snapshots[time].printParentArray();
    }
};

int main() {
    PersistentUnionFind persistentUF(5);

    persistentUF.unionSets(0, 1);
    persistentUF.printParentArray(0);

    persistentUF.unionSets(1, 2);
    persistentUF.printParentArray(1);

    persistentUF.unionSets(3, 4);
    persistentUF.printParentArray(2);

    std::cout << "At time 2, isConnected(0, 3): " << (persistentUF.isConnected(0, 3, 2) ? "true" : "false") << std::endl;

    return 0;
}
