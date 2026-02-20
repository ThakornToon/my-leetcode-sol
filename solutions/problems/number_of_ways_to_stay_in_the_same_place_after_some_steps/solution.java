class Solution {
    private static final int MOD = 1_000_000_007;

    public int numWays(int steps, int arrLen) {
        int maxPos = Math.min(arrLen - 1, steps / 2);
        
        long[] dp = new long[maxPos + 1];
        long[] next = new long[maxPos + 1];
        
        dp[0] = 1;
        
        for (int step = 1; step <= steps; step++) {
            for (int pos = 0; pos <= maxPos; pos++) {
                long ways = dp[pos];  // อยู่ที่เดิม
                
                if (pos > 0) {
                    ways = (ways + dp[pos - 1]) % MOD;  // ซ้าย
                }
                
                if (pos < maxPos) {
                    ways = (ways + dp[pos + 1]) % MOD;  // ขวา
                }
                
                next[pos] = ways;
            }
            
            // สลับ dp และ next
            long[] temp = dp;
            dp = next;
            next = temp;
            
            // clear next
            Arrays.fill(next, 0);
        }
        
        return (int)dp[0];
    }
}