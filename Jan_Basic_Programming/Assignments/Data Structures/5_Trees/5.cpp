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

bool isIdentical(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }

    if (root1 != nullptr && root2 != nullptr)
    {
        bool identical = (isIdentical(root1->left, root2->left)) && (isIdentical(root1->right, root2->right)) && (root1->data == root2->data);
        return identical;
    }
    return false;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int arr2[] = {1, 2, 3, 4, 5, 6, 8};


    TreeNode *root1 = insertNodes(arr1, 0, 6);
    TreeNode *root2 = insertNodes(arr2, 0, 6);
    cout<<"Tree 1 ";
    levelOrderTraversal(root1);

    cout<<"\nTree 2 ";
    levelOrderTraversal(root2);

    if(isIdentical(root1, root2)){
        cout<<"\nBoth Tree are Identical."<<endl;
    }else{
        cout<<"\nBoth Tree are not Identical."<<endl;
    }

    return 0;
}