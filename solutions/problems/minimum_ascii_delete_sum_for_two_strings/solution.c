int minimumDeleteSum(char* s1, char* s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    
    // dp[i][j] = ผลรวม ascii ที่ลยไปเมื่อพิจารณา s1 ยาว i และ s2 ยาว j
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
    }
    
    // Initialize base cases
    dp[0][0] = 0;
    
    // dp[0][j] = sum of ASCII of s2[0..j-1]
    for (int j = 1; j <= n; j++) {
        dp[0][j] = dp[0][j - 1] + s2[j - 1];
    }
    
    // dp[i][0] = sum of ASCII of s1[0..i-1]
    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }
    
    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // Characters match, no deletion needed
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Delete from s1 or s2, choose minimum
                int deleteFromS1 = dp[i - 1][j] + s1[i - 1];
                int deleteFromS2 = dp[i][j - 1] + s2[j - 1];
                dp[i][j] = (deleteFromS1 < deleteFromS2) ? deleteFromS1 : deleteFromS2;
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