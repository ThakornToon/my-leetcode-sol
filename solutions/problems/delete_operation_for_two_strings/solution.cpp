class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // dp[i][j] เก็บความยาว LCS ของ word1[0..i-1] และ word2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int temp = dp[i][j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] =  dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i][j], std::max(dp[i][j - 1], dp[i - 1][j]));
                }
            }
        }

        int lcs = dp[m][n];
        return m + n - 2 * lcs;
    }
};