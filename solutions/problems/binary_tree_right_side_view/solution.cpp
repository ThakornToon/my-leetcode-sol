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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
    
private:
    void dfs(TreeNode* node, int level, vector<int>& result) {
        if (node == nullptr) return;
        
        // ถ้าเป็น level นี้ครั้งแรก (มาจากด้านขวา)
        if (level == result.size()) {
            result.push_back(node->val);
        }
        
        // ไปทางขวาก่อน (เพื่อให้ขวาสุดถูกบันทึกก่อน)
        dfs(node->right, level + 1, result);
        dfs(node->left, level + 1, result);
    }
};