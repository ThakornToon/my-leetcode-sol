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
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*> currentLevel;
        currentLevel.push_back(root);
        
        int maxSum = INT_MIN;
        int maxLevel = 1;
        int level = 1;
        
        while (!currentLevel.empty()) {
            int levelSum = 0;
            vector<TreeNode*> nextLevel;
            
            for (TreeNode* node : currentLevel) {
                levelSum += node->val;
                
                if (node->left) nextLevel.push_back(node->left);
                if (node->right) nextLevel.push_back(node->right);
            }
            
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = level;
            }
            
            currentLevel = nextLevel;
            level++;
        }
        
        return maxLevel;
    }
};