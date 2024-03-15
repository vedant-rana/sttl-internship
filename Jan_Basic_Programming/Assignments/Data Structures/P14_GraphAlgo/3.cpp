    #include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int v) : vertices(v), adjList(v) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void topologicalSortUtil(int vertex, vector<bool>& visited, stack<int>& st) {
        visited[vertex] = true;

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, visited, st);
            }
        }

        st.push(vertex);
    }

    void topologicalSort() {
        vector<bool> visited(vertices, false);
        stack<int> st;

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, st);
            }
        }

        cout << "Topological Sort Order:\n";
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
    }
};

int main() {
    int vertices = 6;
    Graph graph(vertices);

    graph.addEdge(5, 2);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    graph.topologicalSort();

    return 0;
}
