class Solution {
private:
    const int MAX_K = 3;  // 0, 1, 2
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // dp[i][j][k] = เงินสูงสุดถึง (i,j) โดยใช้ neutralize k ครั้ง
        vector<vector<vector<int>>> dp(m, 
            vector<vector<int>>(n, vector<int>(MAX_K, INT_MIN)));
        
        // เริ่มต้นที่ (0,0)
        int val = coins[0][0];
        if (val >= 0) {
            dp[0][0][0] = val;
        } else {
            dp[0][0][0] = val;           // ไม่ neutralize
            if (MAX_K > 1) {
                dp[0][0][1] = 0;          // neutralize
            }
        }
        
        // เติมแถวแรก
        for (int j = 1; j < n; j++) {
            int currVal = coins[0][j];
            for (int k = 0; k < MAX_K; k++) {
                if (dp[0][j-1][k] == INT_MIN) continue;
                
                if (currVal >= 0) {
                    dp[0][j][k] = max(dp[0][j][k], dp[0][j-1][k] + currVal);
                } else {
                    // ไม่ neutralize
                    dp[0][j][k] = max(dp[0][j][k], dp[0][j-1][k] + currVal);
                    // neutralize
                    if (k + 1 < MAX_K) {
                        dp[0][j][k+1] = max(dp[0][j][k+1], dp[0][j-1][k]);
                    }
                }
            }
        }
        
        // เติมคอลัมน์แรก
        for (int i = 1; i < m; i++) {
            int currVal = coins[i][0];
            for (int k = 0; k < MAX_K; k++) {
                if (dp[i-1][0][k] == INT_MIN) continue;
                
                if (currVal >= 0) {
                    dp[i][0][k] = max(dp[i][0][k], dp[i-1][0][k] + currVal);
                } else {
                    dp[i][0][k] = max(dp[i][0][k], dp[i-1][0][k] + currVal);
                    if (k + 1 < MAX_K) {
                        dp[i][0][k+1] = max(dp[i][0][k+1], dp[i-1][0][k]);
                    }
                }
            }
        }
        
        // DP สำหรับเซลล์ที่เหลือ
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int currVal = coins[i][j];
                
                for (int k = 0; k < MAX_K; k++) {
                    int fromTop = dp[i-1][j][k];
                    int fromLeft = dp[i][j-1][k];
                    int bestPrev = max(fromTop, fromLeft);
                    
                    if (bestPrev == INT_MIN) continue;
                    
                    if (currVal >= 0) {
                        dp[i][j][k] = max(dp[i][j][k], bestPrev + currVal);
                    } else {
                        // ไม่ neutralize
                        dp[i][j][k] = max(dp[i][j][k], bestPrev + currVal);
                        // neutralize
                        if (k + 1 < MAX_K) {
                            dp[i][j][k+1] = max(dp[i][j][k+1], bestPrev);
                        }
                    }
                }
            }
        }
        
        // หาค่าสูงสุดที่ (m-1, n-1)
        int result = INT_MIN;
        for (int k = 0; k < MAX_K; k++) {
            result = max(result, dp[m-1][n-1][k]);
        }
        
        return result;
    }
};