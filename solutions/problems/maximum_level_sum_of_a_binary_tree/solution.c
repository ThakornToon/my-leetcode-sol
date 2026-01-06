/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLevelSum(struct TreeNode* root) {
    // ใช้ array 2 ตัวสลับกันแทน queue
    struct TreeNode** currentLevel = malloc(10000 * sizeof(struct TreeNode*));
    struct TreeNode** nextLevel = malloc(10000 * sizeof(struct TreeNode*));
    
    int maxSum = INT_MIN;
    int maxLevel = 1;
    int currentLevelNum = 1;
    
    currentLevel[0] = root;
    int currentSize = 1;
    
    while (currentSize > 0) {
        int levelSum = 0;
        int nextSize = 0;
        
        // Process current level
        for (int i = 0; i < currentSize; i++) {
            struct TreeNode* node = currentLevel[i];
            levelSum += node->val;
            
            // Add children to next level
            if (node->left) {
                nextLevel[nextSize++] = node->left;
            }
            if (node->right) {
                nextLevel[nextSize++] = node->right;
            }
        }
        
        // เช็ค maxSum
        if (levelSum > maxSum) {
            maxSum = levelSum;
            maxLevel = currentLevelNum;
        }
        
        // สลับ next ไปเป็น current
        struct TreeNode** temp = currentLevel;
        currentLevel = nextLevel;
        nextLevel = temp;
        currentSize = nextSize;
        
        currentLevelNum++;
    }
    
    free(currentLevel);
    free(nextLevel);
    return maxLevel;
}