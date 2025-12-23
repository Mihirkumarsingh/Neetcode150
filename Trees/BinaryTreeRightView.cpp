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

TreeNode* buildTree(vector<int>& arr, int i){
    if(i >= arr.size() || arr[i] == -1){
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[i]);
    root->left = buildTree(arr, 2*i+1);
    root->right = buildTree(arr, 2*i+2);
    return root;
}

vector<int> rightSideView(TreeNode* root){
    vector<int> ans;
    if(!root){
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->left){
                q.push(tmp->left);
            }
            if(tmp->right){
                q.push(tmp->right);
            }
            if(size == 0){
                ans.push_back(tmp->val);
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,-1,-1,-1,5};
    TreeNode* root = buildTree(arr, 0);
    vector<int> ans = rightSideView(root);
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}