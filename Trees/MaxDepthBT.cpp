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

    // Depth of left subtree
    int leftDepth = maxDepth(root->left);

    // Depth of right subtree
    int rightDepth = maxDepth(root->right);

    // Take the maximum and add 1 for current node
    int maxSubtreeDepth = max(leftDepth, rightDepth);

    return maxSubtreeDepth + 1;
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

/*
---------------------------------------------------------
DRY RUN (STEP BY STEP EXECUTION)
---------------------------------------------------------

Call:
maxDepth(3)

1) maxDepth(3)
   ├── leftDepth  = maxDepth(9)
   └── rightDepth = maxDepth(20)

2) maxDepth(9)
   ├── leftDepth  = maxDepth(NULL) -> 0
   └── rightDepth = maxDepth(NULL) -> 0
   return max(0, 0) + 1 = 1

3) maxDepth(20)
   ├── leftDepth  = maxDepth(15)
   └── rightDepth = maxDepth(7)

4) maxDepth(15)
   ├── leftDepth  = maxDepth(NULL) -> 0
   └── rightDepth = maxDepth(NULL) -> 0
   return max(0, 0) + 1 = 1

5) maxDepth(7)
   ├── leftDepth  = maxDepth(NULL) -> 0
   └── rightDepth = maxDepth(NULL) -> 0
   return max(0, 0) + 1 = 1

6) Back to maxDepth(20)
   leftDepth  = 1
   rightDepth = 1
   return max(1, 1) + 1 = 2

7) Back to maxDepth(3)
   leftDepth  = 1
   rightDepth = 2
   return max(1, 2) + 1 = 3

FINAL ANSWER:
maxDepth = 3
---------------------------------------------------------
*/