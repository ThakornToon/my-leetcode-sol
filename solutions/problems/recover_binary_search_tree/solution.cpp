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
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;
        
        // Left
        inorder(root->left);
        
        // Root
        if (prev && prev->val > root->val) {
            // ถ้าค่าก่อนหน้ามากกว่าค่าปัจจุบันท แปลว่าค่าก่อนหน้านั้นผิดตำแหน่ง
            if (!first) {
                first = prev;
            }
            second = root;  // หาตำแหน่งที่ first ควรสลับ
        }
        prev = root;
        
        //Right
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = nullptr;
        second = nullptr;
        prev = nullptr;
        
        // Left -> Root -> Right
        // จะเรียงจากน้อยไปมากเสมอ ให้หาจุดที่ผิดสองจุด
        // จุดแรกจะสูงไป จุดที่สองที่เจอจะต่ำไป
        inorder(root);
        
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};