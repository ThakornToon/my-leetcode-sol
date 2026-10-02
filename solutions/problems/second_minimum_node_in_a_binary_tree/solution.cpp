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
    int min2 = -1;

    void dfs(TreeNode* root, int min1) {
        if (!root) return;

        if (root->val > min1) {
            if (min2 == -1 || root->val < min2) {
                min2 = root->val;
            }
            return; // Pruning: ลูกหลานลงไปจะม่ีค่ามากกว่าหรือเท่ากับโหนดนี้ จึงไม่ต้องค้นหาต่อ
        }

        dfs(root->left, min1);
        dfs(root->right, min1);
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        // ค่าของโหนดแม่จะเท่ากับค่าที่น้อยที่สุดระหว่างลูกซ้ายและขวา parent = min(left, right)
        if (!root) return -1;
        dfs(root, root->val);
        return min2;
    }
};