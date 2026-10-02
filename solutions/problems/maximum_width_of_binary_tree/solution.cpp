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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        long long max_width = 0;
        queue<pair<TreeNode*, long long>> q;  // {node, index in slot}
        q.push({root, 0});

        // BFS each row
        while (!q.empty()) {
            int size = q.size();
            long long start = q.front().second;
            long long end = start;

            for (int i = 0; i < size; ++i) {
                auto [node, idx] = q.front();
                q.pop();
                end = idx;

                long long normalized_idx = idx - start;  // ให้เริ่มนับโหนด start ที่ 0 (เหมือนเลื่อน window คิดไม่ให้เกิน long long)

                // โหนดลูก
                if (node->left) {
                    q.push({node->left, 2 * normalized_idx}); 
                }
                if (node->right) {
                    q.push({node->right, 2 * normalized_idx + 1});
                }
            }

            max_width = std::max(max_width, end - start + 1);
        }

        return max_width;
    }
};