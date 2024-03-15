#include <iostream>
#include <vector>
using namespace std;

const int ORDER = 3;

template <typename KeyType, typename ValueType>
struct BTreeNode
{
    bool isLeaf;                  // True if the node is a leaf, false if it's an internal node
    vector<KeyType> keys;         // Keys stored in the node
    vector<ValueType> values;     // Values associated with the keys
    vector<BTreeNode *> children; // Pointers to children nodes

    BTreeNode(bool leaf = true) : isLeaf(leaf) {}
};

// B-tree class
template <typename KeyType, typename ValueType>
class BTree
{
private:
    BTreeNode<KeyType, ValueType> *root; // Root of the B-tree

public:
    BTree() : root(nullptr) {}

    // Function to insert a key-value pair into the B-tree
    void insert(const KeyType &key, const ValueType &value)
    {
        if (!root)
        {
            root = new BTreeNode<KeyType, ValueType>(true);
            root->keys.push_back(key);
            root->values.push_back(value);
        }
        else
        {
            if (root->keys.size() == (ORDER - 1))
            {
                BTreeNode<KeyType, ValueType> *newRoot = new BTreeNode<KeyType, ValueType>(false);
                newRoot->children.push_back(root);
                splitChild(newRoot, 0, root);
                root = newRoot;
            }
            insertNonFull(root, key, value);
        }
    }

    // Function to search for a key in the B-tree
    bool search(const KeyType &key) const
    {
        return searchKey(root, key);
    }

private:
    // Function to insert a key-value pair into a non-full B-tree node
    void insertNonFull(BTreeNode<KeyType, ValueType> *node, const KeyType &key, const ValueType &value)
    {
        int i = node->keys.size() - 1;

        if (node->isLeaf)
        {
            while (i >= 0 && key < node->keys[i])
            {
                i--;
            }
            node->keys.insert(node->keys.begin() + i + 1, key);
            node->values.insert(node->values.begin() + i + 1, value);
        }
        else
        {
            while (i >= 0 && key < node->keys[i])
            {
                i--;
            }

            i++;

            if (node->children[i]->keys.size() == (ORDER - 1))
            {
                splitChild(node, i, node->children[i]);

                if (key > node->keys[i])
                {
                    i++;
                }
            }

            insertNonFull(node->children[i], key, value);
        }
    }

    // Function to split a child node in the B-tree
    void splitChild(BTreeNode<KeyType, ValueType> *parent, int index, BTreeNode<KeyType, ValueType> *child)
    {
        BTreeNode<KeyType, ValueType> *newChild = new BTreeNode<KeyType, ValueType>(child->isLeaf);

        parent->keys.insert(parent->keys.begin() + index, child->keys[ORDER / 2]);
        parent->values.insert(parent->values.begin() + index, child->values[ORDER / 2]);
        parent->children.insert(parent->children.begin() + index + 1, newChild);

        newChild->keys.assign(child->keys.begin() + ORDER / 2 + 1, child->keys.end());
        newChild->values.assign(child->values.begin() + ORDER / 2 + 1, child->values.end());

        child->keys.resize(ORDER / 2);
        child->values.resize(ORDER / 2);

        if (!child->isLeaf)
        {
            newChild->children.assign(child->children.begin() + ORDER / 2 + 1, child->children.end());
            child->children.resize(ORDER / 2 + 1);
        }
    }

    // Function to search for a key in a B-tree node
    bool searchKey(BTreeNode<KeyType, ValueType> *node, const KeyType &key) const
    {
        if (!node)
        {
            return false;
        }

        int i = 0;
        while (i < node->keys.size() && key > node->keys[i])
        {
            i++;
        }

        if (i < node->keys.size() && key == node->keys[i])
        {
            return true;
        }
        else if (node->isLeaf)
        {
            return false;
        }
        else
        {
            return searchKey(node->children[i], key);
        }
    }
};

int main()
{
    BTree<int, string> btree;

    // Insert key-value pairs into the B-tree
    btree.insert(10, "Value 10");
    btree.insert(20, "Value 20");
    btree.insert(5, "Value 5");
    btree.insert(6, "Value 6");
    btree.insert(12, "Value 12");
    btree.insert(30, "Value 30");

    // Search for keys in the B-tree
    cout << "Search for key 10: " << (btree.search(10) ? "Found" : "Not Found") << endl;
    cout << "Search for key 15: " << (btree.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}
