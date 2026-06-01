/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// ฟังก์ชันช่วยสำหรับ recursion
void dfs(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;
    
    // Traverse ซ้าย
    dfs(root->left, result, returnSize);
    
    // เพิ่มค่าปัจจุบัน
    result[(*returnSize)++] = root->val;
    
    // Traverse ขวา
    dfs(root->right, result, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    
    // จองหน่วยความจำสำหรับผลลัพธ์ (maximum nodes)
    int* result = (int*)malloc(100 * sizeof(int)); 
    
    dfs(root, result, returnSize);
    
    return result;
}