class Solution {
private:
    const int MOD = 1000000007;
public:
    int numberOfSets(int n, int k) {
        // dp[i][j] = วิธีที่ใช้ i จุด วาง j segments
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        
        // base case: 0 segments = 1 วิธี (ไม่เลือกอะไรเลย)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int j = 1; j <= k; j++) {
            long long prefix_sum = 0;

            for (int i = j; i <= n; i++) {         
                // วิธีที่ 1: ไม่ใช้จุด i-1
                dp[i][j] = dp[i-1][j];
                
                // วิธีที่ 2: ใช้จุด i-1 เป็น endpoint
                // เลือกจุดเริ่มต้น m (0 ≤ m ≤ i-2) segment นี้จะครอบคลุมจุด m ถึง i-1                
                // ได้จาก dp[1][j-1] + dp[2][j-1] + ... + dp[i-1][j-1]
                dp[i][j] = (dp[i][j] + prefix_sum) % MOD;

                prefix_sum = (prefix_sum + dp[i][j-1]) % MOD;
            }
        }
        
        return dp[n][k];
    }
};