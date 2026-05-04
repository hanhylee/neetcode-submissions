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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> res;
        list<TreeNode*> q = {root};
        unordered_map<TreeNode*, int> levels = {{root, 0}};
        int rightmost_node_val = root->val;
        int level = 0;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop_front();
            int curr_level = levels[curr];

            if (curr_level != level) {
                res.push_back(rightmost_node_val);
                level = curr_level;
            }

            if (curr->left) {
                q.push_back(curr->left);
                levels[curr->left] = curr_level + 1;
            }
            if (curr->right) {
                q.push_back(curr->right);
                levels[curr->right] = curr_level + 1;
            }

            rightmost_node_val = curr->val;
        }

        res.push_back(rightmost_node_val);
        return res;
    }
};
