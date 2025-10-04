class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
         // Possible knight moves
        vector<pair<int, int>> moves = {
            {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
            {1, -2}, {1, 2}, {2, -1}, {2, 1}
        };
        
        // 3D DP array: dp[step][i][j]
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, 
 vector<double>(n, 0.0)));
        
        // Initial position at step 0
        dp[0][row][column] = 1.0;
        
        // For each step
        for (int step = 1; step <= k; step++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // If we can reach (i,j) at previous step
                    if (dp[step-1][i][j] > 0) {
                        // Try all 8 moves
                        for (auto& move : moves) {
                            int ni = i + move.first;
                            int nj = j + move.second;
                            
                            // Check if new position is on board
                            if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                                dp[step][ni][nj] += dp[step-1][i][j] / 8.0;
                            }
                        }
                    }
                }
            }
        }
        
        // Calculate total probability at step k
        double total_prob = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                total_prob += dp[k][i][j];
            }
        }
        
        return total_prob;
    }
};