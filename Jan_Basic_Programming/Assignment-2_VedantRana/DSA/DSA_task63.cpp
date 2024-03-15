#include <iostream>
#include <vector>

class PersistentSegmentTree {
private:
    struct Node {
        int sum;
        int lazy;

        Node() : sum(0), lazy(0) {}
    };

    std::vector<Node> tree;
    std::vector<int> leftChild, rightChild;
    int root, nextFreeIndex;

public:
    PersistentSegmentTree(int n) : tree(1), leftChild(1), rightChild(1), root(0), nextFreeIndex(1) {
        build(1, n, root);
    }

    
    void build(int low, int high, int& node) {
        if (low == high) {
            return;
        }

        node = nextFreeIndex++;
        int mid = (low + high) / 2;

        leftChild[node] = nextFreeIndex;
        build(low, mid, leftChild[node]);

        rightChild[node] = nextFreeIndex;
        build(mid + 1, high, rightChild[node]);
    }

    
    void applyLazy(int node, int low, int high) {
        if (tree[node].lazy != 0) {
            tree[node].sum += tree[node].lazy * (high - low + 1);

            if (low != high) {
                tree[leftChild[node]].lazy += tree[node].lazy;
                tree[rightChild[node]].lazy += tree[node].lazy;
            }

            tree[node].lazy = 0;
        }
    }

    
    void update(int updateLow, int updateHigh, int delta, int& currentNode, int low, int high) {
        
        int newNode = nextFreeIndex++;
        tree.push_back(tree[currentNode]);

        applyLazy(newNode, low, high);

        if (low > updateHigh || high < updateLow) {
            return;
        }

        if (low >= updateLow && high <= updateHigh) {
            tree[newNode].lazy += delta;
            applyLazy(newNode, low, high);
            return;
        }

        int mid = (low + high) / 2;

        leftChild[newNode] = leftChild[currentNode];
        rightChild[newNode] = rightChild[currentNode];

        update(updateLow, updateHigh, delta, leftChild[newNode], low, mid);
        update(updateLow, updateHigh, delta, rightChild[newNode], mid + 1, high);

        tree[newNode].sum = tree[leftChild[newNode]].sum + tree[rightChild[newNode]].sum;
    }

    
    int query(int queryLow, int queryHigh, int currentNode, int low, int high) {
        applyLazy(currentNode, low, high);

        if (low > queryHigh || high < queryLow) {
            return 0;
        }

        if (low >= queryLow && high <= queryHigh) {
            return tree[currentNode].sum;
        }

        int mid = (low + high) / 2;
        int leftSum = query(queryLow, queryHigh, leftChild[currentNode], low, mid);
        int rightSum = query(queryLow, queryHigh, rightChild[currentNode], mid + 1, high);

        return leftSum + rightSum;
    }

    
    void update(int updateLow, int updateHigh, int delta) {
        update(updateLow, updateHigh, delta, root, 1, tree.size() / 2);
    }

    
    int query(int queryLow, int queryHigh) {
        return query(queryLow, queryHigh, root, 1, tree.size() / 2);
    }
};

int main() {
    
    PersistentSegmentTree pst(8);

    pst.update(2, 5, 3);  
    std::cout << "Sum in range [1, 8]: " << pst.query(1, 8) << std::endl;

    pst.update(3, 7, 2);  
    std::cout << "Sum in range [1, 8]: " << pst.query(1, 8) << std::endl;

    return 0;
}
