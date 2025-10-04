double knightProbability(int n, int k, int row, int column) {
    // Possible knight moves
    int moves[8][2] = {{-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1}};
    
    // DP arrays - current and next step
    double** dp = (double**)malloc(n * sizeof(double*));
    double** next_dp = (double**)malloc(n * sizeof(double*));
    
    for (int i = 0; i < n; i++) {
        dp[i] = (double*)calloc(n, sizeof(double));
        next_dp[i] = (double*)calloc(n, sizeof(double));
    }
    
    // Initial position
    dp[row][column] = 1.0;
    
    // For each step
    for (int step = 1; step <= k; step++) {
        // Reset next_dp
        for (int i = 0; i < n; i++) {
            memset(next_dp[i], 0, n * sizeof(double));
        }
        
        // Process each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] > 0) {
                    // Try all 8 moves
                    for (int m = 0; m < 8; m++) {
                        int ni = i + moves[m][0];
                        int nj = j + moves[m][1];
                        
                        // Check if new position is on board
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            next_dp[ni][nj] += dp[i][j] / 8.0;
                        }
                    }
                }
            }
        }
        
        // Swap dp and next_dp for next iteration
        double** temp = dp;
        dp = next_dp;
        next_dp = temp;
    }
    
    // Calculate total probability
    double total_prob = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            total_prob += dp[i][j];
        }
    }
    
    // Free memory
    for (int i = 0; i < n; i++) {
        free(dp[i]);
        free(next_dp[i]);
    }
    free(dp);
    free(next_dp);
    
    return total_prob;
}