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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        
        // ใช้ queue เก็บคู่ของโหนดที่จะเปรียบเทียบ
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            
            // ถ้าทั้งคู่เป็น nullptr ให้ข้ามไป
            if (left == nullptr && right == nullptr) {
                continue;
            }
            
            // ถ้ามีเพียงตัวเดียวเป็น nullptr หรือค่าไม่เท่ากัน
            if (left == nullptr || right == nullptr || left->val != right->val) {
                return false;
            }
            
            // เพิ่มคู่ที่จะเปรียบเทียบในรอบถัดไป
            // ซ้ายของ left กับ ขวาของ right
            q.push(left->left);
            q.push(right->right);
            
            // ขวาของ left กับ ซ้ายของ right
            q.push(left->right);
            q.push(right->left);
        }
        
        return true;
    }
};