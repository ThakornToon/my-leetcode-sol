#define MOD 1000000007

int numWays(int steps, int arrLen) {
    int maxPos = (arrLen - 1 < steps) ? arrLen - 1 : steps;
    
    // dp[pos] = way
    long long* dp = (long long*)calloc(maxPos + 1, sizeof(long long));
    long long* next = (long long*)calloc(maxPos + 1, sizeof(long long));
    
    dp[0] = 1;
    
    for (int step = 1; step <= steps; step++) {
        for (int pos = 0; pos <= maxPos; pos++) {
            // way in current pos
            long long ways = dp[pos];
            
            if (pos > 0) {
                ways = (ways + dp[pos - 1]) % MOD;
            }
            
            if (pos < maxPos) {
                ways = (ways + dp[pos + 1]) % MOD;
            }
            
            next[pos] = ways;
        }
        
        // สลับ dp และ next
        long long* temp = dp;
        dp = next;
        next = temp;
    }
    
    long long result = dp[0];
    
    free(dp);
    free(next);
    
    return (int)result;
}