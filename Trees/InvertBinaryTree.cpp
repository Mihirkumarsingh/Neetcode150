#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){
        val = 0; 
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode* l, TreeNode* r){
        val = x;
        left = l; 
        right = r;
    }
};

TreeNode* buildTree(vector<int>& arr, int i){
    if(i >= arr.size() || arr[i] == -1){
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[i]);
    root->left = buildTree(arr, 2*i+1);
    root->right = buildTree(arr, 2*i+2);
    return root;
}

void printTree(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

TreeNode* invertTree(TreeNode* root){
    if(!root){
        return nullptr;
    }
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}


int main(){
    vector<int> arr = {4,2,7,1,3,6,9};
    TreeNode* root = buildTree(arr, 0);
    cout << "Original: ";
    printTree(root);
    cout << "\n";

    invertTree(root);
    cout << "Inverted: ";
    printTree(root);
    cout << "\n";
    return 0;
}