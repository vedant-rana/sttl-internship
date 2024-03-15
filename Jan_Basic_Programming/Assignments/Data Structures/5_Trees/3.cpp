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


void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    queue<TreeNode*> q;
    q.push(root);

    cout<<"Level Order Traversal : "<<endl;
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

pair<bool, int> isBalanced(TreeNode* root){
    if(root == nullptr){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left= isBalanced(root->left);
    pair<bool, int> right = isBalanced(root->right);

    bool diff = abs(left.second - right.second) <=1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second)+1;

    if(left.first && right.first && diff){
        ans.first =true;
    }else{
        ans.first = false;
    }

    return ans;
}


bool isBalncedTree(TreeNode* root){
    return isBalanced(root).first;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};

    TreeNode* root = insertNodes(arr, 0, 6);

   if(isBalncedTree(root)){
    cout<<"Tree is balanced"<<endl;
   }else{
    cout<<"Tree is Not Balanced"<<endl;
   }

   TreeNode* n1 = new TreeNode(20);
   TreeNode* n2 = new TreeNode(30);


   root->left->left->left = n1;
   n1->left = n2;

   if(isBalncedTree(root)){
    cout<<"Tree is balanced"<<endl;
   }else{
    cout<<"Tree is Not Balanced"<<endl;
   }
    
    return 0;
}