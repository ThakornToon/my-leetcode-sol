int min(int a, int b) {
    return (a <= b) ? a : b;
}

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    int row = dungeonSize;
    int col = dungeonColSize[0];
    int** dp = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        dp[i] = (int*)malloc(sizeof(int) * col);
    }

    if (dungeon[row - 1][col - 1] <= 0) {
        dp[row - 1][col - 1] = 1 - dungeon[row - 1][col - 1];
    } else {
        dp[row - 1][col - 1] = 1;
    }

    for (int r = row - 2; r >= 0; r--) {
        dp[r][col - 1] = dp[r + 1][col - 1] - dungeon[r][col - 1];
        if (dp[r][col - 1] <= 0) {
            dp[r][col - 1] = 1;
        }
    }
    for (int c = col - 2; c >= 0; c--) {
        dp[row - 1][c] = dp[row - 1][c + 1] - dungeon[row - 1][c];
        if (dp[row - 1][c] <= 0) {
            dp[row - 1][c] = 1;
        }
    }

    for (int r = row - 2; r >= 0; r--) {
        for (int c = col - 2; c >= 0; c--) {
            dp[r][c] = min(dp[r + 1][c] - dungeon[r][c], dp[r][c + 1] - dungeon[r][c]);
            if (dp[r][c] <= 0) {
                dp[r][c] = 1;
            }
        }
    }

    int ans = dp[0][0];
    for (int i = 0; i < row; i++) {
        free(dp[i]);
    }
    free(dp);
    return ans;
}