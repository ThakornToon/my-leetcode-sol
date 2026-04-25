#define MOD 1000000007

int numberOfArrays(char* s, int k) {
    int n = strlen(s);
    long long* dp = (long long*)malloc((n + 1) * sizeof(long long));
    memset(dp, 0, (n + 1) * sizeof(long long));
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;  // 0 ไม่สามารถเป็นตัวเลขได้
        
        long long num = 0;

        // แบ่งส่วนปัจจุบัน i ถึง j
        for (int j = i; j < n; j++) {
            num = num * 10 + (s[j] - '0');
            if (num > k) break;
            dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
        }
    }
    
    int result = dp[n];
    free(dp);
    return result;
}