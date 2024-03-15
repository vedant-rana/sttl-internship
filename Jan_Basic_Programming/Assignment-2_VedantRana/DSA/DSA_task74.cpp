#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int CACHE_SIZE = 1024;

template <typename Key, typename Value>
class PersistentBTree {
private:
    struct Node {
        vector<Key> keys;
        vector<Value> values;
        vector<Node*> children;
        bool leaf;

        Node(bool isLeaf) : leaf(isLeaf) {}
    };

    map<int, Node*> versions;  

    
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

    
    Node* insertRecursive(Node* node, const Key& key, const Value& value) {
        if (node == nullptr) {
            Node* newNode = new Node(true);
            newNode->keys.push_back(key);
            newNode->values.push_back(value);
            return newNode;
        }

        int index = upper_bound(node->keys.begin(), node->keys.end(), key) - node->keys.begin();

        if (node->leaf) {
            
            node->keys.insert(node->keys.begin() + index, key);
            node->values.insert(node->values.begin() + index, value);

            
            if (node->keys.size() > 2 * CACHE_SIZE) {
                splitChild(node, index);
            }
        } else {
            
            node->children[index] = insertRecursive(node->children[index], key, value);

            
            if (node->children[index]->keys.size() > 2 * CACHE_SIZE) {
                splitChild(node, index);
            }
        }

        return node;
    }

public:
    PersistentBTree() {}

    
    void insert(int version, const Key& key, const Value& value) {
        if (versions.find(version) == versions.end()) {
            versions[version] = nullptr;
        }

        versions[version] = insertRecursive(versions[version], key, value);
    }

    
};

int main() {
    
    PersistentBTree<int, string> pbtree;

    
    pbtree.insert(1, 1, "Value 1");
    pbtree.insert(1, 2, "Value 2");

    
    pbtree.insert(2, 3, "Value 3");
    pbtree.insert(2, 4, "Value 4");

    
    cout << "Query from version 1:" << endl;
    pbtree.insert(1, 5, "Value 5");
    

    
    cout << "Query from version 2:" << endl;
    pbtree.insert(2, 6, "Value 6");
    

    return 0;
}
