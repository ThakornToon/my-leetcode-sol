class Solution {
private:
    const int MOD = 1000000007;

public:
    int numOfArrays(int n, int m, int k) {
        if (k == 0 || k > m || k > n) return 0;
        
        // dp[len][maxVal][cost] = จำนวนวิธีสร้าง arr ขนาด len มีค่า maxVal ใช้ cost
        vector<vector<vector<int>>> dp(n + 1, 
            vector<vector<int>>(m + 1, 
                vector<int>(k + 1, 0)));
        
        // Base Case
        for (int val = 1; val <= m; val++) {
            dp[1][val][1] = 1;
        }
        
        // DP
        for (int len = 2; len <= n; len++) {
            // prefix sum for optimization
            // prefix[maxVal][cost] = ผลรวม dp[len - 1][i][cost] ที่ i <= maxVal
            vector<vector<int>> prefix(m + 2, vector<int>(k + 2, 0));
            for (int maxVal = 1; maxVal <= m; maxVal++) {
                for (int cost = 1; cost <= k; cost++) {
                    prefix[maxVal][cost] = (prefix[maxVal - 1][cost] + dp[len - 1][maxVal][cost]) % MOD;
                }
            }
            
            for (int maxVal = 1; maxVal <= m; maxVal++) {
                for (int cost = 1; cost <= k; cost++) {
                    long long ways = 0;
                    
                    // ใส่ตัวเลข <= maxVal
                    ways = (ways + (long long)dp[len - 1][maxVal][cost] * maxVal) % MOD;
                    
                    // ใส่ตัวเลข > maxVal (ใช้ prefix sum)
                    // dp[len - 1][1..=maxVal-1][cost - 1]
                    ways = (ways + prefix[maxVal - 1][cost - 1]) % MOD;
                    
                    dp[len][maxVal][cost] = ways;
                }
            }
        }
        
        int result = 0;
        for (int maxVal = 1; maxVal <= m; maxVal++) {
            result = (result + dp[n][maxVal][k]) % MOD;
        }
        
        return result;
    }
};