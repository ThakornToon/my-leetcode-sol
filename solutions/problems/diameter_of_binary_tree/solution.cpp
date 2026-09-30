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
    int max_diameter = 0;

    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        max_diameter = std::max(max_diameter, left + right);

        // คืนค่าความลึกของโหนดนี้กลับขึ้นไป
        return 1 + std::max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        max_diameter = 0;
        maxDepth(root);
        return max_diameter;
    }
};