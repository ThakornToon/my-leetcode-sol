int profitableSchemes(int n, int minProfit, int* group, int groupSize, int* profit, int profitSize) {
    const int MOD = 1e9 + 7;
    // 2D DP พิจารณาปัจจุบันใช้ไป j คน ได้กำไร k = จำนวนวิธี
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int*)malloc((minProfit + 1) * sizeof(int));
        memset(dp[i], 0, (minProfit + 1) * sizeof(int));
    }
    // Base case ใช้ไป 0 คน ได้กำไร 0 มีหนึ่งวิธี
    dp[0][0] = 1;
    
    for (int i = 0; i < groupSize; i++) { // พิจารณาทีละแผย
        int g = group[i];
        int p = profit[i];
        
        // Loop backward
        for (int j = n; j >= g; j--) { 
            for (int k = minProfit; k >= 0; k--) {
                // ไม่เลือกแผนนี้ก็ไม่ต้องทำอะไร curr[j][k] = prev[j][k];

                // เลือกแผนนี้
                int newProfit = k + p;
                if (newProfit > minProfit) newProfit = minProfit;
                
                dp[j][newProfit] = (dp[j][newProfit] + dp[j-g][k]) % MOD;
            }
        }
    }
    
    int ans = 0;
    for (int j = 0; j <= n; j++) { // ได้ >= minProfit
        ans = (ans + dp[j][minProfit]) % MOD;
    }
    
    // Free memory
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return ans;
}