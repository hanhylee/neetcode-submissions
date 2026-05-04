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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        // encode value in a pre-order and in-order traversal separated by a delimiter
        string preorder = preOrder(root);
        cout << preorder << "\n";
        return preorder;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> preorder;
        for (int i=0; i<data.size(); i++) {
            if (data[i] == '#' && data[i+1] != '#') {
                i++;
                string num = "";
                while (i < data.size() && data[i] != '#') {
                    num += data[i];
                    i++;
                }
                i--;
                preorder.push_back(stoi(num));
                cout << stoi(num) << " ";
            }
        }
        cout << endl;
        int idx = 0;
        return vec_to_tree(preorder, idx);
    }

private:
    TreeNode* vec_to_tree(vector<int>& preorder, int& idx) {
        if (preorder.size() <= idx) return nullptr;
        if (preorder[idx] == -1) {
            idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root->left = vec_to_tree(preorder, idx);
        root->right = vec_to_tree(preorder, idx);
        
        return root;
    }

    string preOrder(TreeNode* root) {
        if (root == nullptr) return "-1";
        string s1 = to_string(root->val);
        string s2 = preOrder(root->left);
        string s3 = preOrder(root->right);
        s1 = "#" + s1;
        if (s2 != "") s2 = "#" + s2;
        if (s3 != "") s3 = "#" + s3;
        return s1 + s2 + s3;
    }

};
