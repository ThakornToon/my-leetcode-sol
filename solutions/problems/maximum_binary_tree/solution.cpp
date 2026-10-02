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
    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        // หา max เป็นตัวแบ่งซ้ายขวา
        int max_idx = left;
        for (int i = left + 1; i <= right; ++i) {
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }

        TreeNode* node = new TreeNode(nums[max_idx]);
        node->left = build(nums, left, max_idx - 1);
        node->right = build(nums, max_idx + 1, right);

        return node;

    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};