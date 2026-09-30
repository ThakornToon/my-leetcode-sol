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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // กรณีที่มีลูกข้างเดียว หรือไม่มีลูกเลย
            if (!root->left) {
                TreeNode* right_child = root->right;
                delete root;
                return right_child;
            } else if (!root->right) {
                TreeNode* left_child = root->left;
                delete root;
                return left_child;
            }

            // กรณีที่มีลูกทั้ง 2 ข้าง -> หาค่าน้อยสุดในกิ่งขวาย้ายมาแทน
            TreeNode* curr = root->right;
            while (curr->left) {
                curr = curr->left;
            }

            root->val = curr->val;
            root->right = deleteNode(root->right, curr->val);
        }

        return root;
    }
};