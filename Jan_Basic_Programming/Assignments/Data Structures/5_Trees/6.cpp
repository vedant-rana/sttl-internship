#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode *insertNodes(int arr[], int s, int e)
{
    if (s > e)
    {
        return nullptr;
    }

    int mid = s + (e - s) / 2;

    TreeNode *root = new TreeNode(arr[mid]);

    root->left = insertNodes(arr, s, mid - 1);
    root->right = insertNodes(arr, mid + 1, e);

    return root;
}

TreeNode *buildTree(TreeNode *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new TreeNode(data);

    if (data == -1)
    {
        return nullptr;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    cout << "Level Order Traversal : " << endl;
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();

        if (current == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }
    }
}

TreeNode *getLCA(TreeNode *root, int n1, int n2)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    TreeNode *leftPart = getLCA(root->left, n1, n2);
    TreeNode *rightPart = getLCA(root->right, n1, n2);

    if (leftPart != nullptr && rightPart != nullptr)
    {
        return root;
    }
    else if (leftPart != nullptr && rightPart == nullptr)
    {
        return leftPart;
    }
    else if (leftPart == nullptr && rightPart != nullptr)
    {
        return rightPart;
    }
    else
    {
        return nullptr;
    }
}

int main()
{
    TreeNode *root = nullptr;

    root = buildTree(root);

    levelOrderTraversal(root);

    TreeNode *lca = getLCA(root, 3, 5);

    if (lca)
    {

        cout << "LCA : " << lca->data << endl;
    }
    else
    {
        cout << "LCA not available";
    }

    return 0;
}