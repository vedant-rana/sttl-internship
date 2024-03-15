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

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    TreeNode *root = insertNodes(arr, 0, 6);

    levelOrderTraversal(root);

    return 0;
}