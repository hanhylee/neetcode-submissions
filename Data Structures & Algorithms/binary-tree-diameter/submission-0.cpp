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
    int global_max = 0;
    unordered_map<TreeNode*, int> heights;

    int getHeights(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_height = getHeights(root->left);
        int right_height = getHeights(root->right);
        heights[root] = 1 + max(left_height, right_height);
        return 1 + max(left_height, right_height);
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) return;

        int dist = 0;

        if (root->left) {
            dist += heights[root->left];
            dfs(root->left);
        }
        
        if (root->right) {
            dist += heights[root->right];
            dfs(root->right);
        }

        global_max = max(global_max, dist);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        getHeights(root);
        dfs(root);
        return global_max;
    }
};
