/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode* root, long long minVal, long long maxVal) {
    // Base case: โหนดว่างก็ถือว่า valid
    if (root == NULL) {
        return true;
    }
    
    // ตรวจสอบว่าโหนดปัจจุบันอยู่ในช่วงที่กำหนดหรือไม่
    if (root->val <= minVal || root->val >= maxVal) {
        return false;
    }
    
    // ตรวจสอบ left subtree: ค่าต้องน้อยกว่า root->val
    // ตรวจสอบ right subtree: ค่าต้องมากกว่า root->val
    return dfs(root->left, minVal, root->val) &&
           dfs(root->right, root->val, maxVal);
}

bool isValidBST(struct TreeNode* root) {
    return dfs(root, LLONG_MIN, LLONG_MAX);
}