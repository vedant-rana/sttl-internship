#include <iostream>
#include <vector>

class HeavyLightDecomposition {
private:
    std::vector<std::vector<int>> adj; 
    std::vector<int> parent, depth, chainHead, chainIndex, chainSize, chainPos, nodeValue;
    int chainCount, chainSizeThreshold;

public:
    HeavyLightDecomposition(int n) :
        adj(n), parent(n, -1), depth(n), chainHead(n), chainIndex(n), chainSize(n), chainPos(n), nodeValue(n),
        chainCount(0), chainSizeThreshold(1)
    {
        while ((1 << chainSizeThreshold) <= n) {
            chainSizeThreshold++;
        }

        
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            chainHead[i] = chainIndex[i] = chainPos[i] = i;
        }
    }

    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    void decompose(int u, int parent, int currentChainHead) {
        chainHead[u] = currentChainHead;
        chainIndex[u] = chainCount;
        chainPos[u] = chainSize[chainCount];
        chainSize[chainCount]++;
        int heavyChild = -1, maxSubtreeSize = -1;

        for (int v : adj[u]) {
            if (v != parent && (maxSubtreeSize == -1 || chainSize[v] > chainSize[maxSubtreeSize])) {
                heavyChild = v;
                maxSubtreeSize = v;
            }
        }

        if (heavyChild != -1) {
            decompose(heavyChild, u, currentChainHead);
        }

        for (int v : adj[u]) {
            if (v != parent && v != heavyChild) {
                chainCount++;
                decompose(v, u, v);
            }
        }
    }

    
    void update(int u, int newValue) {
        nodeValue[u] = newValue;
    }

    
    int query(int u, int v) {
        int result = 0;

        while (chainIndex[u] != chainIndex[v]) {
            if (depth[chainHead[u]] < depth[chainHead[v]]) {
                std::swap(u, v);
            }

            
            

            
            for (int i = chainPos[chainHead[u]]; i <= chainPos[u]; ++i) {
                result += nodeValue[i];
            }

            u = parent[chainHead[u]];
        }

      
        for (int i = chainPos[u]; i <= chainPos[v]; ++i) {
            result += nodeValue[i];
        }

        return result;
    }
};

int main() {
    HeavyLightDecomposition hld(10);

    hld.addEdge(0, 1);
    hld.addEdge(0, 2);
    hld.addEdge(1, 3);
    hld.addEdge(1, 4);
    hld.addEdge(2, 5);
    hld.addEdge(5, 6);
    hld.addEdge(5, 7);
    hld.addEdge(7, 8);
    hld.addEdge(7, 9);

    hld.decompose(0, -1, 0);

    hld.update(4, 5);
    std::cout << "Query result (3, 7): " << hld.query(3, 7) << std::endl;

    return 0;
}
