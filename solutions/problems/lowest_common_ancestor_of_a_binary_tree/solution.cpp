/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: หากถึงจุดสิ้นสุด หรือเจอตัวใดตัวหนึ่ง
        if (!root || root == p || root == q) {
            return root;
        }

        // ค้นหาใน subtree ซ้ายและขวา
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // หากพบทั้งสองฝั่ง แสดงว่า root คือจุดบรรจบ (LCA)
        if (left && right) {
            return root;
        }

        // หากพบเพียงฝั่งเดียว ให้ส่งต่อผลลัพธ์ของฝั่งนั้น
        return left ? left : right;
    }
};