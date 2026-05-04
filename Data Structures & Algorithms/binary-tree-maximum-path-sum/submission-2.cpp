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
    int max_path = -1001;

    int dfs(TreeNode* root, int curr_path) {
        if (root == nullptr) return 0;
        curr_path += root->val;

        int left_max_path = max((root->left ? dfs(root->left, curr_path) : 0), 0);
        int right_max_path = max((root->right ? dfs(root->right, curr_path) : 0), 0);

        return max(left_max_path, right_max_path) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        /* INPUT
        given root of binary tree (not BST)
        */

        /* APPROACH
        BFS + DFS
        */
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // get next
            TreeNode* curr = q.front();
            q.pop();

            // get max path using current node (left and right)
            int left_max = max((curr->left ? dfs(curr->left, 0) : 0), 0);
            int right_max = max((curr->right ? dfs(curr->right, 0) : 0), 0);
            max_path = max(max_path, left_max + right_max + curr->val);

            // add to queue
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        /* OUTPUT
        maximum path sum of any non-empty path
        */

        return max_path;
    }
};



/*
TROUBLESHOOTING
root=[-15,10,20,null,null,15,5,-5,-6]
                        -15
                 10              20
                            15        5
                        -5      -6

*/
