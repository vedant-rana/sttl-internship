#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int CACHE_SIZE = 1024; 

template <typename Key, typename Value>
class CacheObliviousBTree {
private:
    struct Node {
        vector<Key> keys;
        vector<Value> values;
        vector<Node*> children;
        bool leaf;

        Node(bool isLeaf) : leaf(isLeaf) {}
    };

    Node* root;

    
    void splitChild(Node* parent, int index) {
        Node* child = parent->children[index];
        Node* newChild = new Node(child->leaf);

        
        Key middleKey = child->keys[child->keys.size() / 2];
        Value middleValue = child->values[child->keys.size() / 2];
        parent->keys.insert(parent->keys.begin() + index, middleKey);
        parent->values.insert(parent->values.begin() + index, middleValue);

        
        newChild->keys.assign(child->keys.begin() + child->keys.size() / 2 + 1, child->keys.end());
        newChild->values.assign(child->values.begin() + child->keys.size() / 2 + 1, child->values.end());

        if (!child->leaf) {
            newChild->children.assign(child->children.begin() + child->children.size() / 2, child->children.end());
        }

        
        child->keys.resize(child->keys.size() / 2);
        child->values.resize(child->values.size() / 2);

        if (!child->leaf) {
            child->children.resize(child->children.size() / 2 + 1);
        }

        
        parent->children.insert(parent->children.begin() + index + 1, newChild);
    }

    
    void insertRecursive(Node* node, const Key& key, const Value& value) {
        int index = upper_bound(node->keys.begin(), node->keys.end(), key) - node->keys.begin();

        if (node->leaf) {
            
            node->keys.insert(node->keys.begin() + index, key);
            node->values.insert(node->values.begin() + index, value);

            
            if (node->keys.size() > 2 * CACHE_SIZE) {
                splitChild(node, index);
            }
        } else {
            
            insertRecursive(node->children[index], key, value);

            
            if (node->children[index]->keys.size() > 2 * CACHE_SIZE) {
                splitChild(node, index);
            }
        }
    }

public:
    CacheObliviousBTree() : root(nullptr) {}

    void insert(const Key& key, const Value& value) {
        if (root == nullptr) {
            root = new Node(true);
            root->keys.push_back(key);
            root->values.push_back(value);
        } else {
            
            if (root->keys.size() > 2 * CACHE_SIZE) {
                Node* newRoot = new Node(false);
                newRoot->children.push_back(root);
                splitChild(newRoot, 0);
                root = newRoot;
            }

            
            insertRecursive(root, key, value);
        }
    }

    
};

int main() {
    
    CacheObliviousBTree<int, string> btree;

    for (int i = 1; i <= 1000; ++i) {
        btree.insert(i, "Value " + to_string(i));
    }

    

    return 0;
}
