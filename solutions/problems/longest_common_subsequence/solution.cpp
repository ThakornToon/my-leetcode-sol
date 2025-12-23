class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        // ใช้แค่ 2 แถวสลับกัน dp[i][j]->dp[j]
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        
        // เมื่อพิจารณา i ตัวแรกใน str1
        for (int i = 1; i <= m; i++) {
            // เมื่อพิจารณากับ j ตัวแรกใน str2
            for (int j = 1; j <= n; j++) {
                // match กันไหม
                if (text1[i - 1] == text2[j - 1]) {
                    // dp[i][j] = dp[i-1][j-1] + 1
                    curr[j] = prev[j - 1] + 1;
                } else {
                    // dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            swap(prev, curr);
        }
        
        return prev[n];
    }
};