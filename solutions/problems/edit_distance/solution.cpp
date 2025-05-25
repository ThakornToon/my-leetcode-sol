class Solution {
public:
    int minDistance(string word1, string word2) {
        int row = word1.length();
        int col = word2.length();
        if (row == 0 || col == 0) {
            return max(row, col);
        }
        if (word1 == word2) {
            return 0;
        }
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        for (int i = 0; i <= row; i++) {
            for (int j = 0; j <= col; j++) {
                if (i==0) {
                    dp[i][j] = j;
                }
                else if (j==0) {
                    dp[i][j] = i;
                }
                else if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else { //else if (word1[i-1] != word2[j-1])
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[row][col];
    }
};