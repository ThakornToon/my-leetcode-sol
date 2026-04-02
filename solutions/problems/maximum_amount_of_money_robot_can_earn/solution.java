class Solution {
    public int maximumAmount(int[][] coins) {
        int m = coins.length;
        int n = coins[0].length;
        final int MAX_K = 3;
        final int NEG = -1_000_000_000;
        
        // dp[j][k] for current row
        int[][] dp = new int[n][MAX_K];
        int[][] prev = new int[n][MAX_K];
        
        // Initialize
        for (int j = 0; j < n; j++) {
            Arrays.fill(prev[j], NEG);
            Arrays.fill(dp[j], NEG);
        }
        
        // First row
        for (int j = 0; j < n; j++) {
            int val = coins[0][j];
            if (j == 0) {
                if (val >= 0) {
                    prev[0][0] = val;
                } else {
                    prev[0][0] = val;
                    if (MAX_K > 1) {
                        prev[0][1] = 0;
                    }
                }
            } else {
                for (int k = 0; k < MAX_K; k++) {
                    if (prev[j-1][k] == NEG) continue;
                    
                    if (val >= 0) {
                        prev[j][k] = Math.max(prev[j][k], prev[j-1][k] + val);
                    } else {
                        prev[j][k] = Math.max(prev[j][k], prev[j-1][k] + val);
                        if (k + 1 < MAX_K) {
                            prev[j][k+1] = Math.max(prev[j][k+1], prev[j-1][k]);
                        }
                    }
                }
            }
        }
        
        // Remaining rows
        for (int i = 1; i < m; i++) {
            // Reset current row
            for (int j = 0; j < n; j++) {
                Arrays.fill(dp[j], NEG);
            }
            
            for (int j = 0; j < n; j++) {
                int val = coins[i][j];
                
                for (int k = 0; k < MAX_K; k++) {
                    int bestPrev = NEG;
                    
                    // From top
                    if (prev[j][k] != NEG) {
                        bestPrev = Math.max(bestPrev, prev[j][k]);
                    }
                    // From left
                    if (j > 0 && dp[j-1][k] != NEG) {
                        bestPrev = Math.max(bestPrev, dp[j-1][k]);
                    }
                    
                    if (bestPrev == NEG) continue;
                    
                    if (val >= 0) {
                        dp[j][k] = Math.max(dp[j][k], bestPrev + val);
                    } else {
                        dp[j][k] = Math.max(dp[j][k], bestPrev + val);
                        if (k + 1 < MAX_K) {
                            dp[j][k+1] = Math.max(dp[j][k+1], bestPrev);
                        }
                    }
                }
            }
            
            // Swap
            int[][] temp = prev;
            prev = dp;
            dp = temp;
        }
        
        int result = NEG;
        for (int k = 0; k < MAX_K; k++) {
            result = Math.max(result, prev[n-1][k]);
        }
        
        return result;
    }
}