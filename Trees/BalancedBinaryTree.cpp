#include<iostream>
using namespace std;

bool ans;

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
    root->left = buildTree(arr, 2*i + 1);
    root->right = buildTree(arr, 2*i + 2);
    return root;
}

void printTree(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << "\n";
    printTree(root->left);
    printTree(root->right);
}

int dfsHeight(TreeNode* root){
    if(!root){
        return 0;
    }
    if(!ans){
        return 0;
    }
    int lh = dfsHeight(root->left);
    int rh = dfsHeight(root->right);
    if(abs(lh-rh) > 1){
        ans = false;
    }
    return max(lh,rh) + 1;
}

bool isBalanced(TreeNode* root){
    ans = true;
    dfsHeight(root);
    return ans;
}
int main(){
    /*
        Input:
        [3,9,20,null,null,15,7]

        Tree:
                3
               / \
              9  20
                 / \
                15  7
    dfsHeight(3)
     ├── dfsHeight(9)
     │    ├── dfsHeight(NULL)
     │    └── dfsHeight(NULL)
     │    → return 1
     └── dfsHeight(20)
          ├── dfsHeight(15)
          │    ├── dfsHeight(NULL)
          │    └── dfsHeight(NULL)
          │    → return 1
          └── dfsHeight(7)
               ├── dfsHeight(NULL)
               └── dfsHeight(NULL)
               → return 1
          → return 2
     → return 3
    */
   
    vector<int> arr = {3,9,20,-1,-1,15,7};
    TreeNode* root = buildTree(arr, 0);

    if (isBalanced(root))
        cout << "Tree is Balanced ✅" << endl;
    else
        cout << "Tree is NOT Balanced ❌" << endl;

    return 0;
}   