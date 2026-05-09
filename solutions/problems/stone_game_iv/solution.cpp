class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> memo(n + 1, -1);
        return dfs(n, memo);
    }

    bool dfs(int n, vector<int>& memo) {
        if (n == 0) return false;
        if (memo[n] != -1) return memo[n];
        
        for (int j = 1; j * j <= n; j++) {
            if (!dfs(n - j * j, memo)) {
                memo[n] = 1;
                return true;
            }
        }

        memo[n] = 0;
        return false;
    }
};