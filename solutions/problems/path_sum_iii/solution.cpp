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
    int dfs(TreeNode* node, long long curr_sum, int target_sum, unordered_map<long long, int>& prefix_map) {
        if (!node) return 0;

        curr_sum += node->val;
        int count = 0;

        // ตรวจสอบว่ามีบรรพบุรุษที่มี prefix sum หักลบแล้วได้ targetSum หรือไม่
        auto it = prefix_map.find(curr_sum - target_sum);
        if (it != prefix_map.end()) {
            count += it->second;
        }

        // บันทึก prefix sum ของโหนดปัจจุบันลงใน map
        prefix_map[curr_sum]++;

        // ท่องลงไปยัง subtree ฝั่งซ้ายและขวา
        count += dfs(node->left, curr_sum, target_sum, prefix_map);
        count += dfs(node->right, curr_sum, target_sum, prefix_map);

        // Backtrack: นำ prefix sum ปัจจุบันออกจาก map ก่อนย้อนกลับ
        prefix_map[curr_sum]--;

        return count;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix_map;
        prefix_map[0] = 1; // ผลรวมเริ่มต้นเป็น 0 (กรณี path เริ่มนับจาก root พอดี)
        return dfs(root, 0, targetSum, prefix_map);
    }
};