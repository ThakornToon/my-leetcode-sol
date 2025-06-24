int checkpalin(char* s, int** dp, int start, int end) {
    if (dp[start][end] != 2) {
        return dp[start][end];
    }

    if (start >= end) {
        dp[start][end] = 1;
    } else if (s[start] != s[end]) {
        dp[start][end] = 0;
    } else {
        dp[start][end] = checkpalin(s, dp, start + 1, end - 1);
    }
    return dp[start][end];
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    int** dp = (int**)malloc(len * sizeof(int*));
    for (int i = 0; i < len; i++) {
        dp[i] = (int*)malloc(len * sizeof(int));
        for (int j = 0; j < len; j++) {
            dp[i][j] = 2; // 2 แทนค่า "ยังไม่คำนวณ"
        }
    }
    int max_len = 1;
    int start_idx = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (checkpalin(s, dp, i, j) && (j - i + 1) > max_len) {
                max_len = j - i + 1;
                start_idx = i;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        free(dp[i]);
    }
    free(dp);
    char* result = (char*)malloc((max_len + 1) * sizeof(char));
    strncpy(result, s + start_idx, max_len);
    result[max_len] = '\0';
    return result;
}