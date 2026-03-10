#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minInsertions(char* s) {
    int n = strlen(s);
    
    // สร้าง DP table
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)calloc(n, sizeof(int));
        dp[i][i] = 1;  // ตัวอักษรเดี่ยวเป็น palindrome
    }
    
    // คำนวณ LPS length
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i + length <= n; i++) {
            int j = i + length - 1;
            
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = MAX(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    
    int lps = dp[0][n - 1];
    int result = n - lps;
    
    // คืนหน่วยความจำ
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}