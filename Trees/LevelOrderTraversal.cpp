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

void printLevelOrder(vector<vector<int>>& res) {
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
            if (j < res[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < res.size() - 1) cout << ",";
    }
    cout << "]";
}

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> ans;
    if(!root){
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);

    //BFS
    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        while(size--){
            TreeNode* curr = q.front();
            q.pop();

            level.push_back(curr->val);

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){
    vector<int> arr = {3, 9 , 20, -1, -1, 15, 7};
    TreeNode* root = buildTree(arr, 0);
    vector<vector<int>> result = levelOrder(root);

    cout << "Output: ";
    printLevelOrder(result);
    return 0;
}

