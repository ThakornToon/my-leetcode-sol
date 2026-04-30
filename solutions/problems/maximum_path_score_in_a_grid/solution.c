
int maxPathScore(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];

    // 3D DP: dp[i][j][cost] = max score
    // ใช้ -1 แทน unreachable
    int*** dp = (int***)malloc(m * sizeof(int**));
    for (int i = 0; i < m; i++) {
        dp[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            dp[i][j] = (int*)malloc((k + 1) * sizeof(int));
            for (int c = 0; c <= k; c++) {
                dp[i][j][c] = -1;
            }
        }
    }
    
    // เริ่มต้นที่ (0,0)
    int startScore = 0, startCost = 0;
    if (grid[0][0] == 1) {
        startScore = 1;
        startCost = 1;
    } else if (grid[0][0] == 2) {
        startScore = 2;
        startCost = 1;
    }
    
    if (startCost <= k) {
        dp[0][0][startCost] = startScore;
    }
    
    // DP
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            
            int cellScore = 0, cellCost = 0;
            if (grid[i][j] == 1) {
                cellScore = 1;
                cellCost = 1;
            } else if (grid[i][j] == 2) {
                cellScore = 2;
                cellCost = 1;
            }
            
            // จากบน (i-1, j)
            if (i > 0) {
                for (int c = 0; c <= k - cellCost; c++) {
                    if (dp[i - 1][j][c] != -1) {
                        int newCost = c + cellCost;
                        int newScore = dp[i - 1][j][c] + cellScore;
                        if (newScore > dp[i][j][newCost]) {
                            dp[i][j][newCost] = newScore;
                        }
                    }
                }
            }
            
            // จากซ้าย (i, j-1)
            if (j > 0) {
                for (int c = 0; c <= k - cellCost; c++) {
                    if (dp[i][j - 1][c] != -1) {
                        int newCost = c + cellCost;
                        int newScore = dp[i][j - 1][c] + cellScore;
                        if (newScore > dp[i][j][newCost]) {
                            dp[i][j][newCost] = newScore;
                        }
                    }
                }
            }
        }
    }
    
    // หาค่าสูงสุดที่ (m-1, n-1) โดย cost <= k
    int maxScore = -1;
    for (int c = 0; c <= k; c++) {
        if (dp[m - 1][n - 1][c] > maxScore) {
            maxScore = dp[m - 1][n - 1][c];
        }
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);
    
    return maxScore;
}