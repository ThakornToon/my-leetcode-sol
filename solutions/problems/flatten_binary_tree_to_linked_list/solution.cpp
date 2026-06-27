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
    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        TreeNode* leftTail = dfs(root->left);
        TreeNode* rightTail = dfs(root->right);
        
        if (root->left != nullptr) {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        
        if (rightTail != nullptr) return rightTail;
        if (leftTail != nullptr) return leftTail;
        return root;
    }
public:
    void flatten(TreeNode* root) {
        dfs(root);
    }
};