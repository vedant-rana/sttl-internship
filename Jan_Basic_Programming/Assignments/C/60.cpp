#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left = nullptr, *right = nullptr;

    TreeNode(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void preOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);

    cout << "pre-order traversal : ";
    preOrder(root);
    cout << endl
         << "in-order traversal : ";
    inOrder(root);
    cout << endl
         << "post-order traversal : ";
    postOrder(root);
    return 0;
}