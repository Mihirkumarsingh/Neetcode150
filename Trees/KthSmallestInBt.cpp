#include <iostream>
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

TreeNode* buildTree(vector<int>& arr, int i) {
    if (i >= arr.size() || arr[i] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[i]);
    root->left = buildTree(arr, 2 * i + 1);
    root->right = buildTree(arr, 2 * i + 2);
    return root;
}

void inOrder(TreeNode* root, vector<int>& arr){
    if(!root){
        return;
    }
    inOrder(root->left, arr);
    arr.push_back(root->val);
    inOrder(root->right, arr);
}


int kthSmallest(TreeNode* root, int k){
    vector<int>arr;
    inOrder(root, arr);
    return arr[k-1];
}

int main(){
    vector<int> arr = {3,1,4,-1,2};
    int k = 1;
    TreeNode* root = buildTree(arr, 0);
    int res =  kthSmallest(root,k);
    cout << res;
    return 0;
}