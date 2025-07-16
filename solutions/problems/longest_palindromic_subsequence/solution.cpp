/*
สร้างตาราง DP ขนาด n x n โดยที่ dp[i][j] แทนความยาวของ LPS ของสตริงย่อยจากตำแหน่ง i ถึง j
ทุกตัวอักษรเป็น palindrome ความยาว 1: dp[i][i] = 1
ถ้าตัวอักษรที่ i และ j เหมือนกัน: dp[i][j] = 2 + dp[i+1][j-1]
ถ้าไม่เหมือน: dp[i][j] = max(dp[i+1][j], dp[i][j-1])
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};