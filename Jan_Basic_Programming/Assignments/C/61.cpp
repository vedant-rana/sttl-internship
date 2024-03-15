#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BSTNode
{
public:
    int data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

BSTNode *insertIntoBST(BSTNode *&root, int d)
{
    if (root == nullptr)
    {
        root = new BSTNode(d);
        return root;
    }

    if (d < root->data)
    {
        root->left = insertIntoBST(root->left, d);
    }
    else
    {
        root->right = insertIntoBST(root->right, d);
    }
    return root;
}

void preOrder(BSTNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

bool searchElement(BSTNode *&root, int search)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == search)
    {
        return true;
    }

    if (search > root->data)
    {
        return searchElement(root->right, search);
    }
    else
    {
        return searchElement(root->left, search);
    }
}

BSTNode *minVal(BSTNode *root)
{
    BSTNode *temp = root;

    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}

BSTNode *deleteNode(BSTNode *root, int val)
{
    if (root == nullptr)
    {
        return root;
    }

    if (root->data == val)
    {
        // 0 child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // 1 child
        // left child
        if (root->left != nullptr && root->right == nullptr)
        {
            BSTNode *t = root->left;
            delete root;
            return t;
        }
        // right child
        if (root->right != nullptr && root->left == nullptr)
        {
            BSTNode *t = root->right;
            delete root;
            return t;
        }

        // 2 child
        if (root->left != nullptr && root->right != nullptr)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deleteNode(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, val);
        return root;
    }
}

int main()
{

    vector<int> nodes = {6, 3, 2, 4, 5, 8, 9};
    BSTNode *root = new BSTNode(nodes[0]);
    int search, del;
    for (int i = 1; i < nodes.size(); i++)
    {
        root = insertIntoBST(root, nodes[i]);
    }

    preOrder(root);

    cout << "Enter element to search : ";
    cin >> search;

    if (searchElement(root, search))
    {
        cout << search << " is found in BST." << endl;
    }
    else
    {
        cout << search << " is not found in BST." << endl;
    }

    cout << "Enter element to delete : ";
    cin >> del;

    root = deleteNode(root, del);
    preOrder(root);

    return 0;
}