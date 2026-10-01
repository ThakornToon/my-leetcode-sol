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
    void dfs(TreeNode* node, int cur_depth, int depth, int val) {
        if (!node) return;

        if (cur_depth == depth - 1) {
            TreeNode* left_sub = node->left;
            TreeNode* right_sub = node->right;

            node->left = new TreeNode(val, left_sub, nullptr);
            node->right = new TreeNode(val, nullptr, right_sub);
            return;
        }

        dfs(node->left, cur_depth + 1, depth, val);
        dfs(node->right, cur_depth + 1, depth, val);
    }
    
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }

        dfs(root, 1, depth, val);
        return root;
    }
};