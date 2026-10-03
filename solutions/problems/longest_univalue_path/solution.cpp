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
    int max_len = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left_path = dfs(node->left);
        int right_path = dfs(node->right);

        int left_extend = 0;
        int right_extend = 0;

        if (node->left && node->left->val == node->val) {
            left_extend = left_path + 1;
        }
        if (node->right && node->right->val == node->val) {
            right_extend = right_path + 1;
        }

        // อัปเดตความยาวเส้นทางสูงสุดที่ผ่านโหนดปัจจุบัน
        max_len = std::max(max_len, left_extend + right_extend);

        // คืนค่ากิ่งที่ยาวที่สุดกลับไปให้โหนดแม่
        return std::max(left_extend, right_extend);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        max_len = 0;
        dfs(root);
        return max_len;
    }
};