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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> output;
        list<TreeNode*> q = {root};
        unordered_map<TreeNode*, int> levels {{root, 0}};
        int curr_level = 0;
        vector<int> curr_level_nodes;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop_front();
            int level = levels[curr];
            if (level != curr_level) {
                output.push_back(curr_level_nodes);
                curr_level = level;
                curr_level_nodes.clear();
            }
            curr_level_nodes.push_back(curr->val);

            if (curr->left) {
                q.push_back(curr->left);
                levels[curr->left] = level + 1;
            }
            if (curr->right) {
                q.push_back(curr->right);
                levels[curr->right] = level + 1;
            }
        }

        if (!curr_level_nodes.empty()) output.push_back(curr_level_nodes);
        return output;
    }
};
