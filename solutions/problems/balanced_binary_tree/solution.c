/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int checkHeight(struct TreeNode* root) {
    if (root == NULL) return 0;
    
    // ตรวจสอบความสูงของ subtree ซ้าย
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;
    
    // ตรวจสอบความสูงของ subtree ขวา
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;
    
    // ตรวจสอบความต่างของความสูง
    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }
    
    // คืนค่าความสูง
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(struct TreeNode* root) {
    return checkHeight(root) != -1;
}