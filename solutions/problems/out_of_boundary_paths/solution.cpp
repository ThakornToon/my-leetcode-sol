class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) return 0;
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1;

        int ans = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int step = 0; step < maxMove; ++step) {
            vector<vector<int>> next_dp(m, vector<int>(n, 0));

            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (dp[r][c] == 0) continue;
                    int count = dp[r][c];

                    for (auto& d : dirs) {
                        int nr = r + d[0];
                        int nc = c + d[1];

                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                            ans = (ans + count) % MOD;
                        } else {
                            next_dp[nr][nc] = (next_dp[nr][nc] + count) % MOD;
                        }
                    }
                }
            }

            dp = std::move(next_dp);
        }

        return ans;
    }
};