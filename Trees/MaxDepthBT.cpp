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
TreeNode* buildTree(vector<int>& arr, int i) {
    if (i >= arr.size() || arr[i] == -1) return nullptr;
    TreeNode* root = new TreeNode(arr[i]);
    root->left = buildTree(arr, 2*i +1);
    root->right = buildTree(arr, 2*i + 2);
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

int maxDepth(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
int main(){
    // Example tree: [3,9,20,-1,-1,15,7]
    vector<int> arr = {3, 9, 20, -1, -1, 15, 7};

    TreeNode* root = buildTree(arr, 0);

    cout << "Tree (preorder): ";
    printTree(root);
    cout << "\n";

    cout << "Max Depth: " << maxDepth(root) << "\n";
    return 0;
}