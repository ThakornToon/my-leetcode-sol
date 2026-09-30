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
    int min_diff = INT_MAX;
    int prev_val = -1;

    // inorder จะไล่จากน้อยไปมาก
    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);  // ได้ prev_val

        if (prev_val != -1) {
            min_diff = std::min(min_diff, node->val - prev_val);
        }
        prev_val = node->val;

        inorder(node->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        min_diff = INT_MAX;
        prev_val = -1;
        inorder(root);
        return min_diff;
    }
};