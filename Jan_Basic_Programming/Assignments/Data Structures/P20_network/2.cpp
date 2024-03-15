#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class FordFulkerson {
    public:
    int vertices;
    vector<vector<int>> capacity;
    vector<vector<int>> residualCapacity;
    vector<vector<int>> graph; 
    
    
    bool bfs(int source, int sink, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        queue<pair<int, int>> q;
        q.push({source, INT_MAX});

        while (!q.empty()) {
            int current = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int neighbor : graph[current]) {
                if (parent[neighbor] == -1 && residualCapacity[current][neighbor] > 0) {
                    parent[neighbor] = current;
                    int newFlow = min(flow, residualCapacity[current][neighbor]);
                    if (neighbor == sink) {
                        return true;  
                    }
                    q.push({neighbor, newFlow});
                }
            }
        }

        return false;  
    }


    void augmentFlow(int source, int sink, vector<int>& parent) {
        int current = sink;
        int newFlow = parent[sink];

        while (current != source) {
            int prev = parent[current];
            residualCapacity[prev][current] -= newFlow;
            residualCapacity[current][prev] += newFlow;
            current = prev;
        }
    }

public:
    FordFulkerson(int v) : vertices(v), capacity(v, vector<int>(v, 0)), graph(v) {}

    void addEdge(int from, int to, int cap) {
        capacity[from][to] = cap;
        graph[from].push_back(to);
        graph[to].push_back(from);  
    }


    int fordFulkerson(int source, int sink) {
        int maxFlow = 0;


        residualCapacity = capacity;

        vector<int> parent(vertices);


        while (bfs(source, sink, parent)) {
            
            augmentFlow(source, sink, parent);


            maxFlow += parent[sink];
        }

        return maxFlow;
    }


    void findMinCut(int source, vector<bool>& reachable) {
        queue<int> q;
        q.push(source);
        reachable[source] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int neighbor : graph[current]) {
                if (!reachable[neighbor] && residualCapacity[current][neighbor] > 0) {
                    q.push(neighbor);
                    reachable[neighbor] = true;
                }
            }
        }
    }
};

int main() {
    FordFulkerson flowNetwork(6);


    flowNetwork.addEdge(0, 1, 16);
    flowNetwork.addEdge(0, 2, 13);
    flowNetwork.addEdge(1, 2, 10);
    flowNetwork.addEdge(1, 3, 12);
    flowNetwork.addEdge(2, 1, 4);
    flowNetwork.addEdge(2, 4, 14);
    flowNetwork.addEdge(3, 2, 9);
    flowNetwork.addEdge(3, 5, 20);
    flowNetwork.addEdge(4, 3, 7);
    flowNetwork.addEdge(4, 5, 4);

    int source = 0;
    int sink = 5;


    int maxFlow = flowNetwork.fordFulkerson(source, sink);

    cout << "Maximum Flow: " << maxFlow << endl;


    vector<bool> reachable(flowNetwork.fordFulkerson(source, sink), false);
    flowNetwork.findMinCut(source, reachable);

    cout << "Minimum Cut (S side): ";
    for (int i = 0; i < flowNetwork.vertices; ++i) {
        if (reachable[i]) {
            cout << i << " ";
        }
    }

    cout << "\nMinimum Cut (T side): ";
    for (int i = 0; i < flowNetwork.vertices; ++i) {
        if (!reachable[i]) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}