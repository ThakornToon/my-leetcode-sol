class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();        
        int n = strs[0].size();
        int count = 0;
        
        for (int j = 0; j < n; j++) {
            bool isSorted = true;
            
            for (int i = 1; i < m; i++) {
                if (strs[i][j] < strs[i - 1][j]) {
                    isSorted = false;
                    break;
                }
            }
            
            if (!isSorted) {
                count++;
            }
        }
        
        return count;
    }
};