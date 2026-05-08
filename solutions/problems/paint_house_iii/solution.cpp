class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // dp[i][j][k] = min cost for house i, color j (1-indexed), k neighborhoods
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(target + 1, INT_MAX)));
        
        // base case: house 0
        for (int color = 1; color <= n; color++) {
            if (houses[0] != 0 && houses[0] != color) continue;
            int c = (houses[0] == 0) ? cost[0][color - 1] : 0;
            dp[0][color][1] = c;
        }
        
        // DP
        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                if (houses[i] != 0 && houses[i] != j) continue;
                
                int paintCost = (houses[i] == 0) ? cost[i][j - 1] : 0;
                
                for (int k = 1; k <= target; k++) {
                    if (dp[i - 1][j][k] != INT_MAX) {
                        // same color as previous house
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + paintCost);
                    }
                    
                    // different color from previous house
                    for (int prevColor = 1; prevColor <= n; prevColor++) {
                        if (prevColor == j) continue;

                        if (dp[i - 1][prevColor][k - 1] != INT_MAX) {
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][prevColor][k - 1] + paintCost);
                        }
                    }
                }
            }
        }
        
        // find answer
        int result = INT_MAX;
        for (int color = 1; color <= n; color++) {
            result = min(result, dp[m - 1][color][target]);
        }
        
        return result == INT_MAX ? -1 : result;
    }
};