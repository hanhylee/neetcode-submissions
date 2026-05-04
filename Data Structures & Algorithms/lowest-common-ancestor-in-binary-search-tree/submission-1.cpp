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
    TreeNode* find_root(TreeNode* p, TreeNode* q) {
        unordered_set<TreeNode*> p_ancestors = {p};
        cout << "p ancestors: " << p->val << " ";
        while (parent[p] != p) {
            p_ancestors.insert(parent[p]);
            p = parent[p];
            cout << p->val << " ";
        }
        
        cout << "\n";

        while (p_ancestors.find(q) == p_ancestors.end()) {
            q = parent[q];
        }

        return q;
    }

    void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return;

        if (root->left) parent[root->left] = root;
        if (root->right) parent[root->right] = root;

        dfs(root->left, p, q);
        dfs(root->right, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parent[root] = root;

        if (root->left) parent[root->left] = root;
        if (root->right) parent[root->right] = root;

        dfs(root->left, p, q);
        dfs(root->right, p, q);

        return find_root(p, q);
    }
    
private:
    unordered_map<TreeNode*, TreeNode*> parent;
};
