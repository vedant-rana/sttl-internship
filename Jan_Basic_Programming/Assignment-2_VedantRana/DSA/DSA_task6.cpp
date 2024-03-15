#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class UnionFind {
private:
    vector<int> parent;

public:
    UnionFind(int n) : parent(n) {
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
            parent[rootX] = rootY;
        }
    }
};

bool equationsPossible(vector<string>& equations) {
    UnionFind uf(26);

    for (const string& equation : equations) {
        if (equation[1] == '=') {
            int x = equation[0] - 'a';
            int y = equation[3] - 'a';
            uf.unionSets(x, y);
        }
    }

    for (const string& equation : equations) {
        if (equation[1] == '!' && uf.find(equation[0] - 'a') == uf.find(equation[3] - 'a')) {
            return false;
        }
    }

    return true;
}

int main() {
    
    vector<string> equations = {"a==b", "b!=c", "c==a"};
    bool satisfiable = equationsPossible(equations);

    if (satisfiable) {
        cout << "The system of equations is satisfiable." << endl;
    } else {
        cout << "The system of equations is not satisfiable." << endl;
    }

    return 0;
}
