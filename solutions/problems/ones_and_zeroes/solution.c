int findMaxForm(char** strs, int strsSize, int m, int n) {
    // Initialize DP table
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)calloc(n + 1, sizeof(int));
    }
    
    for (int k = 0; k < strsSize; k++) {
        // Count zeros and ones in current string
        int zeros = 0, ones = 0;
        char *s = strs[k];
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '0') zeros++;
            else ones++;
        }
        
        // Update DP table from bottom right
        for (int i = m; i >= zeros; i--) {
            for (int j = n; j >= ones; j--) {
                if (dp[i - zeros][j - ones] + 1 > dp[i][j]) {
                    dp[i][j] = dp[i - zeros][j - ones] + 1;
                }
            }
        }
    }
    
    int result = dp[m][n];
    
    // Free memory
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}