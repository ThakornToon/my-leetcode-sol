class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // dp[i][j] = คะแนนส่วนต่างที่ผู้เล่นปัจจุบันได้มากที่สุดเมื่อเล่นบน piles[i..j]
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: กองเดียว
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }
        
        // Fill DP table
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = max(piles[i] - dp[i+1][j],
                               piles[j] - dp[i][j-1]);
            }
        }
        
        return dp[0][n-1] > 0;
    }
};