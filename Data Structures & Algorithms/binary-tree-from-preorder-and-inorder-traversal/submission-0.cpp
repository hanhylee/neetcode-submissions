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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        int idx = 0;

        for (int i=0; i<inorder.size(); i++) {
            if (root->val == inorder[i]) {
                idx = i;
            }
        }

        vector<int> left_inorder(inorder.begin(), inorder.begin() + idx);
        vector<int> right_inorder(inorder.begin() + idx + 1, inorder.end());
        unordered_set<int> left_inorder_set(left_inorder.begin(), left_inorder.end());
        unordered_set<int> right_inorder_set(right_inorder.begin(), right_inorder.end());

        vector<int> left_preorder;
        vector<int> right_preorder;

        for (int num: preorder) {
            if (left_inorder_set.find(num) != left_inorder_set.end()) {
                left_preorder.push_back(num);
            }
            if (right_inorder_set.find(num) != right_inorder_set.end()) {
                right_preorder.push_back(num);
            }
        }
        
        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);

        return root;
    }
};
