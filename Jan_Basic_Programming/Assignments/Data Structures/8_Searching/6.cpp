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

void dfsTraversal(BSTNode *root){
    if(root == nullptr){
        return;
    }

    cout<<root->data<<" ";
    dfsTraversal(root->left);
    dfsTraversal(root->right);
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

    dfsTraversal(root);

    return 0;
}