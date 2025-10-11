int minCostClimbingStairs(int* cost, int costSize) {
    int n = costSize;
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 0;
    dp[1] = 0;
    
    for (int i = 2; i <= n; i++) {
        int oneStep = dp[i-1] + cost[i-1];
        int twoStep = dp[i-2] + cost[i-2];
        dp[i] = oneStep < twoStep ? oneStep : twoStep;
    }
    
    int result = dp[n];
    free(dp);
    return result;
}