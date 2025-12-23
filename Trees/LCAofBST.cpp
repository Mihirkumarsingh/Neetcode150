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

TreeNode* buildTree(vector<int>& arr, int i){
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
TreeNode* LCA(TreeNode* root, TreeNode* p , TreeNode* q){
    if(p->val < root->val && q->val < root->val){
        return LCA(root->left, p, q);
    }else if(p->val > root->val && q->val > root->val){
        return LCA(root->right, p, q);
    }else{
        return root;
    }
}

int main(){
    vector<int> arr = {6,2,8,0,4,7,9,-1,-1,3,5};
    TreeNode* root = buildTree(arr, 0);
    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(4);
    TreeNode* ans = LCA(root, p, q);
    cout << ans->val;
    return 0;
}