class Solution {
    public int minInsertions(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        
        // base case: ตัวอักษรเดี่ยว
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // คำนวณ LPS length
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i + length <= n; i++) {
                int j = i + length - 1;
                
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } 
                dp[i][j] = Math.max(dp[i + 1][j], dp[i][j]);
                dp[i][j] = Math.max(dp[i][j - 1], dp[i][j]);
            }
        }

        return n - dp[0][n - 1];
    }
}