#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class DynamicGraph {
private:
    unordered_map<int, int> parent;

public:
    
    int find(int node) {
        if (parent.find(node) == parent.end() || parent[node] == node) {
            return node;
        } else {
            return parent[node] = find(parent[node]); 
        }
    }

    
    void unite(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);

        if (root1 != root2) {
            parent[root1] = root2;
        }
    }

    
    bool isConnected(int node1, int node2) {
        return find(node1) == find(node2);
    }
};

int main() {
    DynamicGraph dynamicGraph;

    
    dynamicGraph.unite(1, 2);
    dynamicGraph.unite(2, 3);
    dynamicGraph.unite(4, 5);

    
    cout << "Is 1 connected to 3? " << (dynamicGraph.isConnected(1, 3) ? "Yes" : "No") << endl;
    cout << "Is 1 connected to 5? " << (dynamicGraph.isConnected(1, 5) ? "Yes" : "No") << endl;

    
    dynamicGraph.unite(1, 5);
    dynamicGraph.unite(3, 4);

    
    cout << "Is 1 connected to 5 now? " << (dynamicGraph.isConnected(1, 5) ? "Yes" : "No") << endl;

    return 0;
}
