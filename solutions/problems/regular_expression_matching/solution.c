bool isMatch(char* s, char* p) {
    bool** dp = (bool**)calloc(strlen(s) + 1, sizeof(bool*));
    for (int i = 0; i <= strlen(s); i++) {
        dp[i] = (bool*)calloc(strlen(p) + 1, sizeof(bool));
    }
    dp[0][0] = true;
    for (int j = 1; j <= strlen(p); j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j-2];
        }
    }
    for (int i = 1; i <= strlen(s); i++) {
        for (int j = 1; j <= strlen(p); j++) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2]; // Match 0 times
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j]; // Match 1+ times
                }
            }
        }
    }
    bool res = dp[strlen(s)][strlen(p)];
    for (int i = 0; i <= strlen(s); i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}