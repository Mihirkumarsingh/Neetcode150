#include<iostream>
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
    if(i>= arr.size() || arr[i] == -1){
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[i]);
    root->left = buildTree(arr, 2*i+1);
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

bool isSameTree(TreeNode* p, TreeNode* q){
    if(p == NULL && q == NULL ){
        return true;
    }
    if (p == NULL && q != NULL){
        return false;
    }
    
    if (p != NULL && q == NULL){
        return false;
    }

    if(p->val != q->val){
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


bool isSubtree(TreeNode* root, TreeNode* subRoot){
    if(!root){
        return false;
    }else if(isSameTree(root, subRoot)){
        return false;
    }else{
        return isSameTree(root->left, subRoot) || isSameTree(root->right, subRoot);
    }
}

int main(){
    vector<int> p1 = {3,4,5,1,2};
    vector<int> q1 = {4,1,2};

    TreeNode* rootP1 = buildTree(p1, 0);
    TreeNode* rootQ1 = buildTree(q1, 0);
    cout << isSubtree(rootP1, rootQ1);

    return 0;
}