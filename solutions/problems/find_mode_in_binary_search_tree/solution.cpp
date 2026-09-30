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
    int curr_val = 0;
    int curr_count = 0;
    int max_count = 0;
    vector<int> modes;

    // inorder จะเรียงจากน้อยไปมาก
    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);

        // นับความถี่ของค่าปัจจุบัน
        if (curr_count == 0 || node->val != curr_val) {
            curr_val = node->val;
            curr_count = 1;
        } else {
            curr_count++;
        }

        // ปรับฐานนิยม
        if (curr_count > max_count) {
            max_count = curr_count;
            modes.clear();
            modes.push_back(curr_val);
        } else if (curr_count == max_count) {
            modes.push_back(curr_val);
        }

        inorder(node->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
};