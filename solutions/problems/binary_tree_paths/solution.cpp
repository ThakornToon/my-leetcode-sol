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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<string> path;
        dfs(root, path, result);
        return result;
    }
    
private:
    void dfs(TreeNode* node, vector<string>& path, vector<string>& result) {
        if (node == nullptr) return;
        
        // เพิ่ม current node ลง path
        path.push_back(to_string(node->val));
        
        // ถ้าเป็น leaf → สร้าง string และบันทึก
        if (node->left == nullptr && node->right == nullptr) {
            string pathStr;
            for (int i = 0; i < path.size(); i++) {
                if (i > 0) pathStr += "->";
                pathStr += path[i];
            }
            result.push_back(pathStr);
        } else {
            // ไปทางซ้ายและขวา
            dfs(node->left, path, result);
            dfs(node->right, path, result);
        }
        
        // Backtracking
        path.pop_back();
    }
};