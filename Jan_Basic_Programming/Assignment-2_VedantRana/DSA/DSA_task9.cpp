#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxSoldiersInTeam(int N, vector<vector<int>>& arr) {
        unordered_map<int, unordered_set<int>> graph;

        
        for (const auto& connection : arr) {
            int u = connection[0];
            int v = connection[1];

            graph[u].insert(v);
            graph[v].insert(u);
        }

        int maxTeamSize = 0;

        for (int i = 1; i <= N; ++i) {
            unordered_set<int> visited;
            int teamSize = dfs(graph, i, visited);
            maxTeamSize = max(maxTeamSize, teamSize);
        }

        return maxTeamSize;
    }

private:
    int dfs(const unordered_map<int, unordered_set<int>>& graph, int current, unordered_set<int>& visited) {
        if (visited.find(current) != visited.end()) {
            return 0;
        }

        visited.insert(current);
        int teamSize = 1;

        for (int neighbor : graph.at(current)) {
            teamSize += dfs(graph, neighbor, visited);
        }

        return teamSize;
    }
};

int main() {
    Solution solution;

    int N1 = 4;
    vector<vector<int>> arr1 = {{1, 2}, {2, 3}, {2, 4}, {2, 5}};

    int N2 = 8;
    vector<vector<int>> arr2 = {{1, 2}, {2, 3}, {3, 4}, {3, 5}, {6, 7}, {7, 8}, {7, 9}, {7, 10}};

    int N3 = 3;
    vector<vector<int>> arr3 = {{1, 2}, {2, 3}, {3, 1}};

    cout << "Max Soldiers in Team 1: " << solution.maxSoldiersInTeam(N1, arr1) << endl;
    cout << "Max Soldiers in Team 2: " << solution.maxSoldiersInTeam(N2, arr2) << endl;
    cout << "Max Soldiers in Team 3: " << solution.maxSoldiersInTeam(N3, arr3) << endl;

    return 0;
}
