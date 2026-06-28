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
    int maxSum;
    
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int leftGain = max(0, dfs(root->left));   // ถ้าติดลบให้ 0
        int rightGain = max(0, dfs(root->right));
        
        // path ที่ผ่าน node นี้
        int pathSum = root->val + leftGain + rightGain;
        maxSum = max(maxSum, pathSum);
        
        // คืนค่า max gain จาก node นี้ลงล่าง
        return root->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }
};