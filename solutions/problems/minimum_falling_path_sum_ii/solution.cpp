class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<int> prev = grid[0];
        vector<int> curr(n);
        
        for (int i = 1; i < n; i++) {
            // หา smallest และ second smallest จาก prev
            int min1 = INT_MAX, min2 = INT_MAX;
            int idx1 = -1;
            
            for (int j = 0; j < n; j++) {
                if (prev[j] < min1) {
                    min2 = min1;
                    min1 = prev[j];
                    idx1 = j;
                } else if (prev[j] < min2) {
                    min2 = prev[j];
                }
            }
            
            // คำนวณ curr
            for (int j = 0; j < n; j++) {
                if (j != idx1) {
                    curr[j] = grid[i][j] + min1;
                } else {
                    curr[j] = grid[i][j] + min2;
                }
            }
            
            swap(prev, curr);
        }
        
        return *min_element(prev.begin(), prev.end());
    }
};