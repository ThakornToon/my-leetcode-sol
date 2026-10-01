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
private:
    void strPreOrder(TreeNode* root, std::string& s) {
        if (!root) {
            s += ",#";
            return;
        }
        s += "," + to_string(root->val);
        strPreOrder(root->left, s);
        strPreOrder(root->right, s);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s_root = "";
        string s_sub = "";

        strPreOrder(root, s_root);
        strPreOrder(subRoot, s_sub);

        return s_root.find(s_sub) != string::npos;
    }
};