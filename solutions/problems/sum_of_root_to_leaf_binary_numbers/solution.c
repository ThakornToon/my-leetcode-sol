/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int currentSum, int* totalSum) {
    if (root == NULL) return;
    
    // คำนวณค่าใหม่เมื่อเดินมาถึง node นี้
    currentSum = (currentSum << 1) | root->val;
    
    // ถ้าเป็น leaf node
    if (root->left == NULL && root->right == NULL) {
        *totalSum += currentSum;
        return;
    }
    
    // DFS ต่อไป
    dfs(root->left, currentSum, totalSum);
    dfs(root->right, currentSum, totalSum);
}

int sumRootToLeaf(struct TreeNode* root) {
    int totalSum = 0;
    dfs(root, 0, &totalSum);
    return totalSum;
}