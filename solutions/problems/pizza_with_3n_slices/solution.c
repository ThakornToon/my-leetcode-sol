#define MAX_N 500

int max(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}

int getMax(int* slices, int start, int end, int n) {
    int m = end - start + 1;
    int dp[MAX_N][MAX_N] = {0};  // dp[i][j] = เลือก j ชิ้นจาก i ตัวแรก
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // ไม่เลือกชิ้น i
            dp[i][j] = dp[i - 1][j];
            
            // เลือกชิ้น i (ต้องไม่เลือก i-1)
            if (i >= 2) {
                dp[i][j] = max(dp[i][j], dp[i - 2][j - 1] + slices[start + i - 1]);
            } else if (j == 1) {
                dp[i][j] = max(dp[i][j], slices[start + i - 1]);
            }
        }
    }
    
    return dp[m][n];
}

int maxSizeSlices(int* slices, int slicesSize) {
    if (slicesSize == 1) {
        return slices[0];
    }

    int n = slicesSize / 3;

    // เลือกที่ 0 จะเลือก n - 1 ไม่ได้
    // ไม่เลือกที่ 0 จะเลือก n - 1 ได้
    return max(getMax(slices, 0, slicesSize - 2, n), getMax(slices, 1, slicesSize - 1, n));
}
