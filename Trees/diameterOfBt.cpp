#include<iostream>
using namespace std;
struct TreeNode{
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

TreeNode* buildTree(vector<int>& arr, int i ){
    if(i >= arr.size() || arr[i] == -1){
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[i]);
    root->left = buildTree(arr, 2*i + 1);
    root->right = buildTree(arr, 2*i+2);
    return root;
}

void printTree(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " " << "\n";
    printTree(root->left);
    printTree(root->right);
}

int height(TreeNode* root, int &dia){
    if(!root){
        return 0;
    }
    int lHeight = height(root->left, dia);
    int rHeight = height(root->right, dia);
    dia = max(dia, lHeight+rHeight);
    return 1 + max(lHeight, rHeight);
}

int diameterOfBinaryTree(TreeNode* root){
    int dia = 0;
    height(root, dia);
    return dia;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    TreeNode* root = buildTree(arr, 0);
    cout << "Tree (preorder): ";
    printTree(root);
    
    int ans = diameterOfBinaryTree(root);
    cout << "\nFinal Diameter = " << ans << "\n";
    return 0;
}