class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j] = dot product ที่ดีที่สุดเมื่อพิจารณา nums1 ยาว i และ nums2 ยาว j
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN / 2));
        
        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int product = nums1[i - 1] * nums2[j - 1];
                
                dp[i][j] = max({
                    dp[i - 1][j - 1] + product,  // Continue previous subsequence
                    product,                      // Start new subsequence
                    dp[i - 1][j],                // Skip nums1[i-1]
                    dp[i][j - 1]                 // Skip nums2[j-1]
                });
            }
        }
        
        return dp[m][n];
    }
};