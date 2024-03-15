#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int minCostToSupplyWater(int N, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<vector<int>> connections;
        
        
        for (int i = 0; i < N; ++i) {
            connections.push_back({0, i + 1, wells[i]});
        }
        
        
        for (const auto& pipe : pipes) {
            connections.push_back(pipe);
        }
        
        
        sort(connections.begin(), connections.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        
        vector<int> parent(N + 1);
        iota(parent.begin(), parent.end(), 0);

        int minCost = 0;

        
        for (const auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];
            int cost = connection[2];

            int rootU = find(parent, u);
            int rootV = find(parent, v);

            if (rootU != rootV) {
                
                minCost += cost;
                
                parent[rootU] = rootV;
            }
        }

        return minCost;
    }

private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
};

int main() {
    Solution solution;

    int N1 = 3;
    vector<int> wells1 = {1, 2, 2};
    vector<vector<int>> pipes1 = {{1, 2, 1}, {2, 3, 1}};

    int N2 = 4;
    vector<int> wells2 = {1, 1, 1, 1};
    vector<vector<int>> pipes2 = {{1, 2, 100}, {2, 3, 100}, {2, 4, 50}};

    cout << "Minimum Cost for Case 1: " << solution.minCostToSupplyWater(N1, wells1, pipes1) << endl;
    cout << "Minimum Cost for Case 2: " << solution.minCostToSupplyWater(N2, wells2, pipes2) << endl;

    return 0;
}
