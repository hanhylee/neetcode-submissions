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
    bool isValidBSTBounded(TreeNode* root, long min_bound, long max_bound) {
        if (root == nullptr) return true;

        if (root->val <= min_bound || root->val >= max_bound) return false;
        
        return isValidBSTBounded(root->left, min_bound, root->val) && isValidBSTBounded(root->right, root->val, max_bound);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTBounded(root, LONG_MIN, LONG_MAX);
    }
};