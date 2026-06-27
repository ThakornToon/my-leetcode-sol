/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    // Base case: ต้นไม้ว่าง
    if (root == NULL) {
        return 0;
    }
    
    // หาความลึกของ subtree ซ้ายและขวา
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    // ความลึกของต้นนี้ = 1 + max(ซ้าย, ขวา)
    return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
}