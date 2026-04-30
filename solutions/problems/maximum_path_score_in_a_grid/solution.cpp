class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j][c] = max score ถึง (i,j) ด้วย cost c
        vector<vector<vector<int>>> dp(m, 
            vector<vector<int>>(n, vector<int>(k + 1, -1)));
        
        // เริ่มต้นที่ (0,0)
        int startScore = 0, startCost = 0;
        if (grid[0][0] == 1) {
            startScore = 1;
            startCost = 1;
        } else if (grid[0][0] == 2) {
            startScore = 2;
            startCost = 1;
        }
        
        if (startCost <= k) {
            dp[0][0][startCost] = startScore;
        }
        
        // DP
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                
                int cellScore = 0, cellCost = 0;
                if (grid[i][j] == 1) {
                    cellScore = 1;
                    cellCost = 1;
                } else if (grid[i][j] == 2) {
                    cellScore = 2;
                    cellCost = 1;
                }
                
                // จากบน
                if (i > 0) {
                    for (int c = 0; c <= k - cellCost; c++) {
                        if (dp[i - 1][j][c] != -1) {
                            int newCost = c + cellCost;
                            int newScore = dp[i - 1][j][c] + cellScore;
                            dp[i][j][newCost] = max(dp[i][j][newCost], newScore);
                        }
                    }
                }
                
                // จากซ้าย
                if (j > 0) {
                    for (int c = 0; c <= k - cellCost; c++) {
                        if (dp[i][j - 1][c] != -1) {
                            int newCost = c + cellCost;
                            int newScore = dp[i][j - 1][c] + cellScore;
                            dp[i][j][newCost] = max(dp[i][j][newCost], newScore);
                        }
                    }
                }
            }
        }
        
        // หาค่าสูงสุดที่ (m-1, n-1)
        int maxScore = -1;
        for (int c = 0; c <= k; c++) {
            maxScore = max(maxScore, dp[m - 1][n - 1][c]);
        }
        
        return maxScore;
    }
};