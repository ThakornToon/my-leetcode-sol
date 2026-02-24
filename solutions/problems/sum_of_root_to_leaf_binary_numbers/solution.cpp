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
    int sumRootToLeaf(TreeNode* root) {
        int totalSum = 0;
        dfs(root, 0, totalSum);
        return totalSum;
    }
private:
    void dfs(TreeNode* node, int currentSum, int& totalSum) {
        if (node == nullptr) return;
        
        // คำนวณค่าใหม่
        currentSum = (currentSum << 1) | node->val;
        
        // ถ้าเป็น leaf
        if (node->left == nullptr && node->right == nullptr) {
            totalSum += currentSum;
            return;
        }
        
        // DFS ต่อไป
        dfs(node->left, currentSum, totalSum);
        dfs(node->right, currentSum, totalSum);
    }
};