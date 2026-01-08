class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        
        // dp[i][j] = dot product ที่ดีที่สุดเมื่อพิจารณา nums1 ยาว i และ nums2 ยาว j
        int[][] dp = new int[m + 1][n + 1];
        
        // Initialize with minimum value
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = Integer.MIN_VALUE / 2;
            }
        }
        
        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int product = nums1[i - 1] * nums2[j - 1];
                
                dp[i][j] = Math.max(
                    Math.max(dp[i - 1][j - 1] + product, product),
                    Math.max(dp[i - 1][j], dp[i][j - 1])
                );
            }
        }
        
        return dp[m][n];
    }
}