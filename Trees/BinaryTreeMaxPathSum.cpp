#include <iostream>
using namespace std;

/*
    Binary Tree node definition
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int maxPathDown(TreeNode* node, int &maxi) {

    // ---------------- BASE CASE ----------------
    // If node is NULL, it contributes 0 to the path
    if (node == NULL)
        return 0;

    // ---------------- RECURSIVE CALLS ----------------
    // Get max downward path sum from left subtree
    int left = maxPathDown(node->left, maxi);

    // If left path is negative, ignore it
    // Because negative sum only reduces our total
    if (left < 0)
        left = 0;

    // Get max downward path sum from right subtree
    int right = maxPathDown(node->right, maxi);

    // Ignore negative right path as well
    if (right < 0)
        right = 0;

    // ---------------- UPDATE GLOBAL ANSWER ----------------
    /*
        At current node, we try forming a path like:
        
            left subtree
                 \
                  node
                 /
            right subtree

        Path sum = left + node->val + right

        This path CANNOT be extended upwards, but it can be the final answer
    */
    maxi = max(maxi, left + right + node->val);

    // ---------------- RETURN VALUE TO PARENT ----------------
    /*
        When returning to parent:
        - We can only choose ONE side (left OR right)
        - Because a path cannot fork upwards

        So we return:
            node->val + max(left, right)
    */
    return max(left, right) + node->val;
}

int main() {

    /*
        Constructing the tree from input:
        root = [-10, 9, 20, null, null, 15, 7]

                -10
                /  \
               9   20
                   / \
                 15   7
    */

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Initialize maximum path sum to very small value
    int maxi = INT_MIN;

    // Call DFS
    maxPathDown(root, maxi);

    // Final answer
    cout << "Maximum Path Sum = " << maxi << endl;

    /*
        STEP-BY-STEP EXECUTION (IMPORTANT):

        Node 9:
            left = 0, right = 0
            maxi = max(-inf, 9) = 9
            return 9

        Node 15:
            left = 0, right = 0
            maxi = max(9, 15) = 15
            return 15

        Node 7:
            left = 0, right = 0
            maxi = max(15, 7) = 15
            return 7

        Node 20:
            left = 15, right = 7
            maxi = max(15, 15 + 20 + 7) = 42
            return 20 + max(15, 7) = 35

        Node -10:
            left = 9, right = 35
            maxi = max(42, 9 + (-10) + 35) = 42
            return 25 (ignored)

        FINAL ANSWER = 42
        Path = 15 -> 20 -> 7
    */

    return 0;
}

/*
    TIME COMPLEXITY:
        O(N)
        - Each node is visited exactly once

    SPACE COMPLEXITY:
        O(H)
        - Recursive call stack
        - H = height of tree
        - Worst case (skewed): O(N)
        - Balanced tree: O(log N)

    CORE INTUITION:
        - Drop negative paths
        - At every node:
            * Try forming a path through it
            * Return best single path upward
*/