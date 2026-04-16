class Solution {
private:
    static const int MAX_N = 500;
    
    int getMax(vector<int>& slices, int start, int end, int n) {
        int m = end - start + 1;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // ไม่เลือกชิ้น i
                dp[i][j] = dp[i - 1][j];
                
                // เลือกชิ้น i (ต้องไม่เลือก i-1)
                if (i >= 2) {
                    dp[i][j] = max(dp[i][j], dp[i - 2][j - 1] + slices[start + i - 1]);
                } else if (j == 1) {
                    dp[i][j] = max(dp[i][j], slices[start + i - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
    
public:
    int maxSizeSlices(vector<int>& slices) {
        if (slices.size() == 1) {
            return slices[0];
        }
        
        int n = slices.size() / 3;
        
        // กรณี 1: ไม่เลือกชิ้นสุดท้าย (เลือกได้ถึงชิ้นที่ n-2)
        // กรณี 2: ไม่เลือกชิ้นแรก (เลือกได้ตั้งแต่ชิ้นที่ 1)
        return max(getMax(slices, 0, slices.size() - 2, n),
                   getMax(slices, 1, slices.size() - 1, n));
    }
};