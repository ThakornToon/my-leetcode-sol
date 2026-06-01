/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // Base case: ทั้งคู่เป็น NULL
    if (p == NULL && q == NULL) {
        return true;
    }
    
    // Base case: มีข้างใดข้างหนึ่งเป็น NULL
    if (p == NULL || q == NULL) {
        return false;
    }
    
    // ตรวจสอบว่า node ปัจจุบันมีค่าเท่ากัน
    // และ subtree ซ้ายและขวาเหมือนกัน
    if (p->val != q->val) {
        return false;
    }
    
    // ตรวจสอบ left subtree และ right subtree แบบ recursive
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}