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
    unordered_map<int, int> count;
    int max_freq = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int sum = root->val + dfs(root->left) + dfs(root->right);
        max_freq = max(max_freq, ++count[sum]);
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);

        vector<int> result;
        for (auto& [sum, freq] : count) {
            if (freq == max_freq) {
                result.push_back(sum);
            }
        }

        return result;
    }
};