#include <iostream>
#include<queue>
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
void dfs(TreeNode* node, int curMax, int& count){
    if(!node){
        return;
    }
    if(node->val >= curMax){
        count++;
        curMax = node->val;
    }
    dfs(node->left, curMax, count);
    dfs(node->right, curMax, count);
}

int goodNodes(TreeNode* root){
    if(!root){
        return 0;
    }
    int count = 0;
    dfs(root, root->val, count);
    return count;
}

int main(){
    vector<int> arr = {3, 1, 4, 3, -1, 1, 5};
    TreeNode* root = buildTree(arr, 0);
    int result = goodNodes(root);
    cout << result;
    return 0;
}
