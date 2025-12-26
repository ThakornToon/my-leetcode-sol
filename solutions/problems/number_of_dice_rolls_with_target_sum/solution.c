int numRollsToTarget(int n, int k, int target) {
    const int MOD = 1000000007;
    
    // ใช้ dp 2 มิติ
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int*)malloc((target + 1) * sizeof(int));
        memset(dp[i], 0, (target + 1) * sizeof(int));
    }
    
    dp[0][0] = 1;
    
    for (int dice = 1; dice <= n; dice++) {
        for (int sum = 1; sum <= target; sum++) {
            long long ways = 0;
            
            // ลูกเต๋าล่าสุดสามารถมีค่าได้ 1 ถึง k
            for (int face = 1; face <= k; face++) {
                if (sum >= face) {
                    ways += dp[dice-1][sum-face];
                    ways %= MOD;
                }
            }
            
            dp[dice][sum] = ways;
        }
    }
    
    int result = dp[n][target];
    
    // free memory
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}