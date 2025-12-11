class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        
        // สร้าง DP table
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Initialize first row
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        
        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // คำนวณจากแถวก่อนหน้า
                int left = (j > 0) ? dp[i-1][j-1] : INT_MAX;
                int middle = dp[i-1][j];
                int right = (j < n-1) ? dp[i-1][j+1] : INT_MAX;
                
                dp[i][j] = matrix[i][j] + min({left, middle, right});
            }
        }
        
        // หาค่าต่ำสุดในแถวสุดท้าย
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};