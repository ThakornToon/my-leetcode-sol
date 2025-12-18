class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        
        // Check feasibility
        if ((n - 1) % (k - 1) != 0) return -1;
        
        // Prefix sum
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }
        
        // DP table
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Process intervals of increasing length
        for (int len = k; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                
                // Try all possible splits
                for (int m = i; m < j; m += k - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
                }
                
                // If we can merge into one pile
                if ((len - 1) % (k - 1) == 0) {
                    dp[i][j] += prefix[j + 1] - prefix[i];
                }
            }
        }
        
        return dp[0][n - 1];
    }
};