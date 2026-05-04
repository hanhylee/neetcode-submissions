/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        int left_height = dfs(root->left);
        int right_height = dfs(root->right);

        if (left_height == -1 || right_height == -1) return -1;
        if (abs(left_height - right_height) > 1) return -1;

        return 1 + max(left_height, right_height);
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        if (dfs(root) == -1) return false;
        return true;
    }
};
