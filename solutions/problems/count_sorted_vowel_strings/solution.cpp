class Solution {
public:
    int countVowelStrings(int n) {
        // DP: dp[i][j] = จำนวนสตริงความยาว i ที่ลงท้ายด้วยสระ j
        // j: 0=a, 1=e, 2=i, 3=o, 4=u
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        
        // base case: ความยาว 1
        for (int j = 0; j < 5; j++) {
            dp[1][j] = 1;
        }
        
        // transition
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k <= j; k++) {
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        
        // รวมทุกสระที่ลงท้าย
        int result = 0;
        for (int j = 0; j < 5; j++) {
            result += dp[n][j];
        }
        
        return result;
    }
};