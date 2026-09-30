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
    int sum = 0;

    // Right -> Root -> Left
    void reverseInorder(TreeNode* node) {
        if (!node) return;

        // ท่อง subtree ฝั่งขวาก่อน
        reverseInorder(node->right);

        // ผลรวมสะสมและค่าของโหนดปัจจุบัน
        sum += node->val;
        node->val = sum;

        // ท่อง subtree ฝั่งซ้าย
        reverseInorder(node->left);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        reverseInorder(root);
        return root;
    }
};