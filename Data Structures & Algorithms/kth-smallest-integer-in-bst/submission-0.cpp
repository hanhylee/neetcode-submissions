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
    void dfs(TreeNode* root, vector<int>& node_vals) {
        if (root == nullptr) return;
        node_vals.push_back(root->val);
        dfs(root->left, node_vals);
        dfs(root->right, node_vals);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> node_vals;
        dfs(root, node_vals);

        priority_queue<int, vector<int>, greater<int>> sorted_node_vals(node_vals.begin(), node_vals.end());

        for (int i=0; i<k-1; i++) {
            sorted_node_vals.pop();
        }

        return sorted_node_vals.top();
    }
};
