int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1);
    int n = strlen(text2);
    
    // dp[i][j] เมื่อพิจารณา str1 i ตัวแรก และ str2 j ตัวแรก จับคู่กันได้ความยาวมากสุดเท่าไร
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                int left = dp[i][j - 1];
                int up = dp[i - 1][j];
                dp[i][j] = (left > up) ? left : up;
            }
        }
    }
    
    int result = dp[m][n];
    
    // คืนหน่วยความจำ
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}