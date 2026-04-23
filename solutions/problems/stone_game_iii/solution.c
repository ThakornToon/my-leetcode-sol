char* stoneGameIII(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[n] = 0;  // ไม่มีหินแล้ว
    
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = INT_MIN;
        int sum = 0;
        
        // ลองหยิบ 1, 2, หรือ 3 กอง
        for (int k = 1; k <= 3 && i + k - 1 < n; k++) {
            sum += stoneValue[i + k - 1];
            dp[i] = MAX(dp[i], sum - dp[i + k]);
        }
    }
    
    char* result;
    if (dp[0] > 0) {
        result = "Alice";
    } else if (dp[0] < 0) {
        result = "Bob";
    } else {
        result = "Tie";
    }
    
    free(dp);
    return result;
}