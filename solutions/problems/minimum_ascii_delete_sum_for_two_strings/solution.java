class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();

        // dp[i][j] = ผลรวม ascii ที่ลบไปเมื่อพิจารณา s1 ยาว i และ s2 ยาว j
        int[][] dp = new int[m + 1][n + 1];
        
        // Initialize first row: delete all from s2
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] + s2.charAt(j - 1);
        }
        
        // Initialize first column: delete all from s1
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] + s1.charAt(i - 1);
        }
        
        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    // Characters match, no deletion needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Delete from s1 or s2
                    int deleteFromS1 = dp[i - 1][j] + s1.charAt(i - 1);
                    int deleteFromS2 = dp[i][j - 1] + s2.charAt(j - 1);
                    dp[i][j] = Math.min(deleteFromS1, deleteFromS2);
                }
            }
        }
        
        return dp[m][n];
    }
}