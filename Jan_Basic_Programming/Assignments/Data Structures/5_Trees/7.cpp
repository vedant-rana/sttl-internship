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

void inOrderTraverse(TreeNode* root){
    stack<TreeNode*>st;
    TreeNode* cur =root;

    while(cur != nullptr || !st.empty()){
        while(cur != nullptr){
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        cout<<cur->data<<" ";

        cur = cur->right;
    }
}

void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};

    TreeNode* root = insertNodes(arr, 0, 6);

    inOrderTraverse(root);
    
    return 0;
}