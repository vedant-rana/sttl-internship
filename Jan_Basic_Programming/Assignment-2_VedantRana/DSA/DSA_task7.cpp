#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;

        
        for (int i = 0; i < equations.size(); ++i) {
            const string& numerator = equations[i][0];
            const string& denominator = equations[i][1];
            double value = values[i];

            graph[numerator][denominator] = value;
            graph[denominator][numerator] = 1.0 / value;
        }

        vector<double> results;
        for (const auto& query : queries) {
            const string& start = query[0];
            const string& target = query[1];

            unordered_set<string> visited;
            double result = dfs(graph, start, target, visited);

            results.push_back(result);
        }

        return results;
    }

private:
    double dfs(const unordered_map<string, unordered_map<string, double>>& graph,
               const string& current, const string& target, unordered_set<string>& visited) {
        if (graph.find(current) == graph.end() || graph.find(target) == graph.end()) {
            return -1.0;
        }

        if (current == target) {
            return 1.0;
        }

        visited.insert(current);

        for (const auto& neighbor : graph.at(current)) {
            const string& next = neighbor.first;
            if (visited.find(next) == visited.end()) {
                double result = dfs(graph, next, target, visited);
                if (result != -1.0) {
                    return neighbor.second * result;
                }
            }
        }

        return -1.0;
    }
};

int main() {
    Solution solution;

    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    vector<double> results = solution.calcEquation(equations, values, queries);

    cout << "Results:" << endl;
    for (double result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
