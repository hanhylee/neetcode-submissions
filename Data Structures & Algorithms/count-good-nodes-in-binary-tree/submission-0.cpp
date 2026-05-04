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
    int dfs(TreeNode* root, int max_val) {
        if (root == nullptr) return 0;

        int num_left = 0, num_right = 0;

        if (root->left) {
            num_left = dfs(root->left, max(root->val, max_val));
        }
        
        if (root->right) {
            num_right = dfs(root->right, max(root->val, max_val));
        }
        
        if (root->val < max_val) {
            cout << "current branch is no good because " << root->val << " < " << max_val << "\n";
            return 0 + num_left + num_right;
        }

        return 1 + num_left + num_right;
        
    }

    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int num_left = 0, num_right = 0;

        if (root->left) {
            num_left = dfs(root->left, root->val);
        }
        
        if (root->right) {
            num_right = dfs(root->right, root->val);
        }

        return 1 + num_left + num_right;
    }
};
