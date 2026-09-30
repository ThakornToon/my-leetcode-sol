/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int depth, int* max_depth, int* ans) {
    if (!root) return;

    if (depth > *max_depth) {
        *max_depth = depth;
        *ans = root->val;
    }

    dfs(root->left, depth + 1, max_depth, ans);
    dfs(root->right, depth + 1, max_depth, ans);
}

int findBottomLeftValue(struct TreeNode* root) {
    int max_depth = -1;
    int ans = 0;

    dfs(root, 0, &max_depth, &ans);

    return ans;
}