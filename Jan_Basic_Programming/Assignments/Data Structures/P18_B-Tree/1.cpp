#include <iostream>
using namespace std;
const int t = 2;

class BTreeNode
{
public:
    int n;
    int keys[2 * t - 1];
    BTreeNode *children[2 * t];
    bool leaf;

    BTreeNode(bool leafNode) : n(0), leaf(leafNode)
    {
        for (int i = 0; i < 2 * t; ++i)
            children[i] = nullptr;
    }
};

class BTree
{
private:
    BTreeNode *root;

public:
    BTree() : root(nullptr) {}

    void insert(int key)
    {
        if (root == nullptr)
        {
            root = new BTreeNode(true);
            root->keys[0] = key;
            root->n = 1;
        }
        else
        {
            if (root->n == 2 * t - 1)
            {
                BTreeNode *newRoot = new BTreeNode(false);
                newRoot->children[0] = root;
                splitChild(newRoot, 0);
                root = newRoot;
            }
            insertNonFull(root, key);
        }
    }

    void remove(int key)
    {
        if (root == nullptr)
        {
            cout << "Tree is empty. Cannot delete.\n";
        }
        else
        {
            removeKey(root, key);

            if (root->n == 0)
            {
                BTreeNode *temp = root;
                root = root->children[0];
                delete temp;
            }
        }
    }

    bool search(int key)
    {
        return searchKey(root, key);
    }

    void printInOrder()
    {
        if (root != nullptr)
            inOrderTraversal(root);
        cout << endl;
    }

private:
    void insertNonFull(BTreeNode *node, int key)
    {
        int i = node->n - 1;

        if (node->leaf)
        {
            while (i >= 0 && key < node->keys[i])
            {
                node->keys[i + 1] = node->keys[i];
                --i;
            }

            node->keys[i + 1] = key;
            ++node->n;
        }
        else
        {
            while (i >= 0 && key < node->keys[i])
                --i;

            ++i;

            if (node->children[i]->n == 2 * t - 1)
            {
                splitChild(node, i);

                if (key > node->keys[i])
                    ++i;
            }

            insertNonFull(node->children[i], key);
        }
    }

    void splitChild(BTreeNode *parent, int index)
    {
        BTreeNode *child = parent->children[index];
        BTreeNode *newChild = new BTreeNode(child->leaf);

        parent->n++;
        parent->keys[index] = child->keys[t - 1];

        for (int i = 0; i < t - 1; ++i)
        {
            newChild->keys[i] = child->keys[i + t];
            child->keys[i + t] = 0;
        }

        if (!child->leaf)
        {
            for (int i = 0; i < t; ++i)
            {
                newChild->children[i] = child->children[i + t];
                child->children[i + t] = nullptr;
            }
        }

        newChild->n = t - 1;
        child->n = t - 1;

        for (int i = parent->n; i > index + 1; --i)
            parent->children[i] = parent->children[i - 1];

        parent->children[index + 1] = newChild;
    }

    void removeKey(BTreeNode *node, int key)
    {
        int index = findKeyIndex(node, key);

        if (index < node->n && node->keys[index] == key)
        {
            if (node->leaf)
            {
                removeFromLeaf(node, index);
            }
            else
            {
                removeFromNonLeaf(node, index);
            }
        }
        else
        {
            if (node->leaf)
            {
                cout << "Key " << key << " not found in the tree.\n";
                return;
            }

            bool lastChild = (index == node->n);

            if (node->children[index]->n < t)
            {
                fillChild(node, index);
            }

            if (lastChild && index > node->n)
                removeKey(node->children[index - 1], key);
            else
                removeKey(node->children[index], key);
        }
    }

    void removeFromLeaf(BTreeNode *node, int index)
    {
        for (int i = index + 1; i < node->n; ++i)
        {
            node->keys[i - 1] = node->keys[i];
        }

        node->n--;
    }

    void removeFromNonLeaf(BTreeNode *node, int index)
    {
        int key = node->keys[index];

        if (node->children[index]->n >= t)
        {
            int predecessor = getPredecessor(node, index);
            node->keys[index] = predecessor;
            removeKey(node->children[index], predecessor);
        }
        else if (node->children[index + 1]->n >= t)
        {
            int successor = getSuccessor(node, index);
            node->keys[index] = successor;
            removeKey(node->children[index + 1], successor);
        }
        else
        {
            merge(node, index);
            removeKey(node->children[index], key);
        }
    }

    int findKeyIndex(BTreeNode *node, int key)
    {
        int index = 0;
        while (index < node->n && key > node->keys[index])
            ++index;
        return index;
    }

    int getPredecessor(BTreeNode *node, int index)
    {
        BTreeNode *child = node->children[index];
        while (!child->leaf)
            child = child->children[child->n];
        return child->keys[child->n - 1];
    }

    int getSuccessor(BTreeNode *node, int index)
    {
        BTreeNode *child = node->children[index + 1];
        while (!child->leaf)
            child = child->children[0];
        return child->keys[0];
    }

    void fillChild(BTreeNode *node, int index)
    {
        if (index != 0 && node->children[index - 1]->n >= t)
        {
            borrowFromPrev(node, index);
        }
        else if (index != node->n && node->children[index + 1]->n >= t)
        {
            borrowFromNext(node, index);
        }
        else
        {
            if (index != node->n)
                merge(node, index);
            else
                merge(node, index - 1);
        }
    }

    void borrowFromPrev(BTreeNode *node, int index)
    {
        BTreeNode *child = node->children[index];
        BTreeNode *sibling = node->children[index - 1];

        for (int i = child->n - 1; i >= 0; --i)
        {
            child->keys[i + 1] = child->keys[i];
        }

        if (!child->leaf)
        {
            for (int i = child->n; i >= 0; --i)
            {
                child->children[i + 1] = child->children[i];
            }
        }

        child->keys[0] = node->keys[index - 1];

        if (!child->leaf)
        {
            child->children[0] = sibling->children[sibling->n];
        }

        node->keys[index - 1] = sibling->keys[sibling->n - 1];

        child->n++;
        sibling->n--;
    }

    void borrowFromNext(BTreeNode *node, int index)
    {
        BTreeNode *child = node->children[index];
        BTreeNode *sibling = node->children[index + 1];

        child->keys[child->n] = node->keys[index];

        if (!child->leaf)
        {
            child->children[child->n + 1] = sibling->children[0];
        }

        node->keys[index] = sibling->keys[0];

        for (int i = 1; i < sibling->n; ++i)
        {
            sibling->keys[i - 1] = sibling->keys[i];
        }

        if (!sibling->leaf)
        {
            for (int i = 1; i <= sibling->n; ++i)
            {
                sibling->children[i - 1] = sibling->children[i];
            }
        }

        child->n++;
        sibling->n--;
    }

    void merge(BTreeNode *node, int index)
    {
        BTreeNode *child = node->children[index];
        BTreeNode *sibling = node->children[index + 1];

        child->keys[t - 1] = node->keys[index];

        for (int i = 0; i < sibling->n; ++i)
        {
            child->keys[i + t] = sibling->keys[i];
        }

        if (!child->leaf)
        {
            for (int i = 0; i <= sibling->n; ++i)
            {
                child->children[i + t] = sibling->children[i];
            }
        }

        for (int i = index + 1; i < node->n; ++i)
        {
            node->keys[i - 1] = node->keys[i];
        }

        for (int i = index + 2; i <= node->n; ++i)
        {
            node->children[i - 1] = node->children[i];
        }

        child->n += sibling->n + 1;
        node->n--;

        delete sibling;
    }

    bool searchKey(BTreeNode *node, int key)
    {
        int i = 0;
        while (i < node->n && key > node->keys[i])
            ++i;

        if (i < node->n && key == node->keys[i])
            return true;

        if (node->leaf)
            return false;

        return searchKey(node->children[i], key);
    }

    void inOrderTraversal(BTreeNode *node)
    {
        int i;
        for (i = 0; i < node->n; ++i)
        {
            if (!node->leaf)
                inOrderTraversal(node->children[i]);
            cout << node->keys[i] << " ";
        }

        if (!node->leaf)
            inOrderTraversal(node->children[i]);
    }
};

int main()
{
    BTree btree;

    btree.insert(3);
    btree.insert(7);
    btree.insert(1);
    btree.insert(5);
    btree.insert(10);
    btree.insert(2);
    btree.insert(6);
    btree.insert(9);
    btree.insert(11);
    btree.insert(4);
    btree.insert(8);

    cout << "In-order traversal of the B-tree after insertion: ";
    btree.printInOrder();

    cout << "Search for key 6: " << (btree.search(6) ? "Found" : "Not Found") << endl;
    cout << "Search for key 12: " << (btree.search(12) ? "Found" : "Not Found") << endl;

    btree.remove(6);
    btree.remove(11);

    cout << "In-order traversal of the B-tree after deletion: ";
    btree.printInOrder();

    return 0;
}
