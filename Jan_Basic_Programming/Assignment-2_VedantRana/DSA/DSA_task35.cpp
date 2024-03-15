#include <iostream>
#include <vector>

const int t = 2; 

class BTreeNode {
public:
    bool leaf;
    std::vector<int> keys;
    std::vector<BTreeNode*> children;

    BTreeNode(bool isLeaf) : leaf(isLeaf) {}

    
    void insertNonFull(int k) {
        int i = keys.size() - 1;

        
        if (leaf) {
            
            while (i >= 0 && k < keys[i]) {
                keys[i + 1] = keys[i];
                i--;
            }

            
            keys[i + 1] = k;
        } else {
            
            while (i >= 0 && k < keys[i])
                i--;

            
            if (children[i + 1]->keys.size() == (2 * t - 1)) {
                splitChild(i + 1, children[i + 1]);

                
                if (k > keys[i + 1])
                    i++;
            }

            
            children[i + 1]->insertNonFull(k);
        }
    }

    
    void splitChild(int i, BTreeNode* y) {
        BTreeNode* z = new BTreeNode(y->leaf);
        z->keys.resize(t - 1);

        
        for (int j = 0; j < t - 1; j++)
            z->keys[j] = y->keys[j + t];

        
        if (!y->leaf) {
            for (int j = 0; j < t; j++)
                z->children.push_back(y->children[j + t]);
            y->children.resize(t);
        }

        
        y->keys.resize(t - 1);

        
        keys.insert(keys.begin() + i, y->keys[t - 1]);
        children.insert(children.begin() + i + 1, z);
    }

    
    void traverse() {
        int i;
        for (i = 0; i < keys.size(); i++) {
            
            
            if (!leaf)
                children[i]->traverse();
            std::cout << " " << keys[i];
        }

        
        if (!leaf)
            children[i]->traverse();
    }
};

class BTree {
private:
    BTreeNode* root;

public:
    BTree() : root(nullptr) {}

    
    void insert(int k) {
        
        if (!root) {
            root = new BTreeNode(true);
            root->keys.push_back(k);
        } else {
            
            if (root->keys.size() == (2 * t - 1)) {
                BTreeNode* s = new BTreeNode(false);
                s->children.push_back(root);
                s->splitChild(0, root);
                root = s;
            }

            
            root->insertNonFull(k);
        }
    }

    
    void traverse() {
        if (root)
            root->traverse();
    }
};

int main() {
    BTree btree;

    
    btree.insert(3);
    btree.insert(7);
    btree.insert(1);
    btree.insert(5);
    btree.insert(10);
    btree.insert(12);
    btree.insert(6);
    btree.insert(9);
    btree.insert(8);
    btree.insert(11);

    std::cout << "B-Tree traversal: ";
    btree.traverse();
    std::cout << std::endl;

    return 0;
}
