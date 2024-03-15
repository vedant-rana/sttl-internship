#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode* insertNodes(int arr[], int s, int e){
    if(s>e){
        return nullptr;
    }

    int mid=s+(e-s)/2;

    TreeNode* root = new TreeNode(arr[mid]);

    root->left = insertNodes(arr, s, mid-1);
    root->right = insertNodes(arr, mid+1, e);

    return root;

}

int getHeight(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight, rightHeight)+1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};

    TreeNode* root = insertNodes(arr, 0, 8);

    cout<<"Height of Tree : "<<getHeight(root)<<endl;

    return 0;
}