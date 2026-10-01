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
    void dfs(TreeNode* root, std::string& res) {
        if (!root) return;

        res += to_string(root->val);

        // หากมีลูกซ้าย หรือมีลูกขวา ต้องสร้างวงเล็บให้ลูกซ้ายเสมอ
        if (root->left || root->right) {
            res += '(';
            dfs(root->left, res);
            res += ')';
        }

        // สร้างวงเล็บให้ลูกขวาเฉพาะเมื่อมีลูกขวาอยู่จริง
        if (root->right) {
            res += '(';
            dfs(root->right, res);
            res += ')';
        }
    }
public:
    string tree2str(TreeNode* root) {
        string res = "";
        dfs(root, res);
        return res;
    }
};