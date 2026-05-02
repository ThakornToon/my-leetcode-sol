#define MOD 1000000007

int numOfArrays(int n, int m, int k) {
    if (k == 0 || k > m || k > n) return 0;
    
    // dp[len][maxVal][cost]
    int*** dp = (int***)malloc((n + 1) * sizeof(int**));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int**)malloc((m + 1) * sizeof(int*));
        for (int j = 0; j <= m; j++) {
            dp[i][j] = (int*)calloc(k + 1, sizeof(int));
        }
    }
    
    // base case: ความยาว 1, ค่าสูงสุด = val, cost = 1
    for (int val = 1; val <= m; val++) {
        dp[1][val][1] = 1;
    }
    
    for (int len = 2; len <= n; len++) {
        for (int maxVal = 1; maxVal <= m; maxVal++) {
            for (int cost = 1; cost <= k; cost++) {
                long long ways = 0;
                
                // กรณี 1: ใส่ตัวเลข <= maxVal (cost ไม่เพิ่ม)
                // ใส่เลข 1..maxVal
                ways = (ways + (long long)dp[len - 1][maxVal][cost] * maxVal) % MOD;
                
                // กรณี 2: ใส่ตัวเลข > maxVal (cost เพิ่ม 1)
                // ใส่เลข maxVal+1 .. m
                for (int newMax = maxVal + 1; newMax <= m; newMax++) {
                    ways = (ways + dp[len - 1][newMax][cost - 1]) % MOD;
                }
                
                dp[len][maxVal][cost] = (int)ways;
            }
        }
    }
    
    int result = 0;
    for (int maxVal = 1; maxVal <= m; maxVal++) {
        result = (result + dp[n][maxVal][k]) % MOD;
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);
    
    return result;
}