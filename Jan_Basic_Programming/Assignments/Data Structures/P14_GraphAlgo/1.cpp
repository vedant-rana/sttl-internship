#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;
    vector<vector<int>> revAdjList;

public:
    Graph(int v) : vertices(v), adjList(v), revAdjList(v) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        revAdjList[v].push_back(u);
    }

    void dfs(int vertex, vector<bool>& visited, stack<int>& st, vector<vector<int>>& graph) {
        visited[vertex] = true;

        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, st, graph);
            }
        }

        st.push(vertex);
    }

    void fillOrder(stack<int>& st) {
        vector<bool> visited(vertices, false);

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                dfs(i, visited, st, adjList);
            }
        }
    }

    void dfsSCC(int vertex, vector<bool>& visited, vector<int>& scc, vector<vector<int>>& graph) {
        visited[vertex] = true;
        scc.push_back(vertex);

        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                dfsSCC(neighbor, visited, scc, graph);
            }
        }
    }

    vector<vector<int>> findSCCs() {
        stack<int> orderStack;
        fillOrder(orderStack);

        vector<bool> visited(vertices, false);
        vector<vector<int>> sccs;

        while (!orderStack.empty()) {
            int vertex = orderStack.top();
            orderStack.pop();

            if (!visited[vertex]) {
                vector<int> scc;
                dfsSCC(vertex, visited, scc, revAdjList);

                sccs.push_back(scc);
            }
        }

        return sccs;
    }
};

int main() {
    int vertices = 5;
    Graph graph(vertices);
    
    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 1);
    graph.addEdge(0, 3);
    graph.addEdge(3, 4);

    vector<vector<int>> sccs = graph.findSCCs();

    cout << "Strongly Connected Components:\n";
    for (const vector<int>& scc : sccs) {
        cout << "[ ";
        for (int vertex : scc) {
            cout << vertex << " ";
        }
        cout << "]\n";
    }

    return 0;
}
