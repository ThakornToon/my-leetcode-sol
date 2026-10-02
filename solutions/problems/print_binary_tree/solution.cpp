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
    int getHeight(TreeNode* root) {
        if (!root) return -1;
        return 1 + std::max(getHeight(root->left), getHeight(root->right));
    }

    void nextLevel(TreeNode* root, int row, int lc, int rc, vector<vector<string>>& res) {
        if (!root) return;
        int mid = lc + (rc - lc) / 2;
        res[row][mid] = to_string(root->val);
        nextLevel(root->left, row + 1, lc, mid - 1, res);
        nextLevel(root->right, row + 1, mid + 1, rc, res);
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        int m = h + 1;
        int n = (1 << (h + 1)) - 1;

        vector<vector<string>> res(m, vector<string>(n, ""));
        nextLevel(root, 0, 0, n - 1, res);
        return res;
    }
};