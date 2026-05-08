class Solution {
    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        int INF = 1_000_000_000;
        
        // dp[color][k]
        int[][] dp = new int[n + 1][target + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], INF);
        }
        
        // base case: house 0
        for (int color = 1; color <= n; color++) {
            if (houses[0] != 0 && houses[0] != color) continue;
            int c = (houses[0] == 0) ? cost[0][color - 1] : 0;
            dp[color][1] = c;
        }
        
        // DP for each house
        for (int i = 1; i < m; i++) {
            int[][] newDp = new int[n + 1][target + 1];
            for (int j = 0; j <= n; j++) {
                Arrays.fill(newDp[j], INF);
            }
            
            for (int j = 1; j <= n; j++) {
                if (houses[i] != 0 && houses[i] != j) continue;
                
                int paintCost = (houses[i] == 0) ? cost[i][j - 1] : 0;
                
                for (int k = 1; k <= target; k++) {
                    // same color
                    if (dp[j][k] != INF) {
                        newDp[j][k] = Math.min(newDp[j][k], dp[j][k] + paintCost);
                    }
                    
                    // different color
                    for (int prevColor = 1; prevColor <= n; prevColor++) {
                        if (prevColor == j) continue;
                        if (dp[prevColor][k - 1] != INF) {
                            newDp[j][k] = Math.min(newDp[j][k], dp[prevColor][k - 1] + paintCost);
                        }
                    }
                }
            }
            
            dp = newDp;
        }
        
        int result = INF;
        for (int color = 1; color <= n; color++) {
            result = Math.min(result, dp[color][target]);
        }
        
        return result == INF ? -1 : result;
    }
}