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
    // pair.first  = ขโมยโหนดปัจจุบัน (rob_this)
    // pair.second = ไม่ขโมยโหนดปัจจุบัน (not_rob_this)
    std::pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int rob_this = root->val + left.second + right.second;
        int not_rob_this = std::max(left.first, left.second) + 
                           std::max(right.first, right.second);

        return {rob_this, not_rob_this};
    }
public:
    int rob(TreeNode* root) {
        auto [rob_this, not_rob_this] = dfs(root);
        return std::max(rob_this, not_rob_this);
    }
};