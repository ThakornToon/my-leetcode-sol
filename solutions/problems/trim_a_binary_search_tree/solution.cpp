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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;

        // ตัดโหนดปัจจุบันและทางซ้ายทั้งหมด
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }

        // ตัดโหนดปัจจุบันและทางซ้ายทั้งหมด
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }

        // ปรับค่าทางซ้ายและขวาให้อยู๋ในขอบเขตด้วย จะได้โหนดที่ควรอยู่เป็น root ทางซ้ายและขวามา
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};