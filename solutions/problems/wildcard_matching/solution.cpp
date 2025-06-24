class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        // สร้างตาราง DP 2 มิติ
        vector<std::vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-1];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '?' || p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                    // dp[i][j-1]: ใช้ * แทนสตริงว่าง (มองข้าม *)
                    // dp[i-1][j]: ใช้ * แทนอักขระปัจจุบันและย้อนพิจารณาตัวก่อนหน้าว่าจะใช้ไหม
                }
            }
        }
        
        return dp[m][n];
    }
};