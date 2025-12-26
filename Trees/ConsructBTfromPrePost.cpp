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

    TreeNode(int x, TreeNode* l, TreeNode* r) {
        val = x;
        left = l;
        right = r;
    }
};

int preInd = 0;

TreeNode* buildTree(vector<int>& arr, int i){
    if(i >= arr.size() || arr[i] == -1){
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[i]);
    root->left = buildTree(arr, 2*i + 1);
    root->right = buildTree(arr, 2*i + 2);
    return root;
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int start, int end){
    if(start > end){
        return nullptr;
    }

    // Create root from preorder
    TreeNode* node = new TreeNode(preorder[preInd++]);

    // Find root in inorder
    int pos = start;
    for(int i = start; i <= end; i++){
        if(inorder[i] == node->val){
            pos = i;
            break;
        }
    }

    node->left = createTree(preorder, inorder, start, pos - 1);
    node->right = createTree(preorder, inorder, pos + 1, end);

    return node;
}

TreeNode* buildTreeFromPreAndPost(vector<int>& preorder, vector<int>& inorder) {
    preInd = 0;
    return createTree(preorder, inorder, 0, inorder.size() - 1);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};

    TreeNode* root = buildTreeFromPreAndPost(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
