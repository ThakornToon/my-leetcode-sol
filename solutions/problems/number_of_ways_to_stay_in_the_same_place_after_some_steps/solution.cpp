class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1e9 + 7;
        
        // ลดขอบเขต: ไม่ต้องพิจารณาตำแหน่งที่ > steps/2
        int maxPos = min(arrLen - 1, steps / 2);
        
        vector<long long> dp(maxPos + 1, 0);
        vector<long long> next(maxPos + 1, 0);
        
        dp[0] = 1;
        
        for (int step = 1; step <= steps; step++) {
            for (int pos = 0; pos <= maxPos; pos++) {
                long long ways = dp[pos];  // อยู่ที่เดิม
                
                if (pos > 0) {
                    ways = (ways + dp[pos - 1]) % MOD;  // เลื่อนซ้าย
                }
                
                if (pos < maxPos) {
                    ways = (ways + dp[pos + 1]) % MOD;  // เลื่อนขวา
                }
                
                next[pos] = ways;
            }
            
            swap(dp, next);
        }
        
        return dp[0];
    }
};