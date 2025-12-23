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


bool isValid(TreeNode* root){
    if(!root){
        return true;
    }
    vector<int>arr;
    inOrder(root, arr);
    for(int i = 1; i<arr.size(); i++){ 
        if(arr[i] <= arr[i-1]){ 
            return false; 
        } 
    }
    return true;
}

int main(){
    vector<int> arr = {5,1,4,-1,-1,3,6};
    TreeNode* root = buildTree(arr, 0);
    cout << isValid(root)<< endl;
    return 0;
}