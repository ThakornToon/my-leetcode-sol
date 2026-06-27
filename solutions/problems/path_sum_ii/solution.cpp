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
    void dfs(TreeNode* node, int targetSum, vector<int>& path, vector<vector<int>>& result) {
        if (node == nullptr) return;
        
        // เพิ่มค่า node ลงใน path
        path.push_back(node->val);
        
        // ถ้าเป็น leaf
        if (node->left == nullptr && node->right == nullptr) {
            if (targetSum == node->val) {
                result.push_back(path);
            }
        } else {
            // เรียก DFS ไปที่ลูก (ลด targetSum)
            int newTarget = targetSum - node->val;
            dfs(node->left, newTarget, path, result);
            dfs(node->right, newTarget, path, result);
        }
        
        // Backtracking: ลบค่า node ออกจาก path
        path.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, path, result);
        return result;
    }
};