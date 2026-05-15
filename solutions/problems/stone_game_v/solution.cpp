class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // prefix sums
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        
        // DP table
        // dp[i][j] คือผลลัพธ์ที่ดีที่สุดจากการเล่นในส่วน i ถึง j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                
                // ลองแบ่งทุกตำแหน่ง k (i <= k < j) เพื่อหาค่าที่ดีที่สุด
                for (int k = i; k < j; k++) {
                    int sumLeft = prefix[k + 1] - prefix[i];
                    int sumRight = prefix[j + 1] - prefix[k + 1];
                    
                    if (sumLeft < sumRight) {  // ฝั่งขวาถูกโยน
                        dp[i][j] = max(dp[i][j], sumLeft + dp[i][k]);
                    } else if (sumLeft > sumRight) {  // ฝั่งซ้ายถูกโยน
                        dp[i][j] = max(dp[i][j], sumRight + dp[k + 1][j]);
                    } else {  // sumLeft == sumRight
                        dp[i][j] = max(dp[i][j], sumLeft + max(dp[i][k], dp[k + 1][j]));
                    }
                }
            }
        }
        
        return dp[0][n - 1];
    }
};