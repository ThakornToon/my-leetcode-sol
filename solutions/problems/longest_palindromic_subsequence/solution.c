/*
สร้างตาราง DP ขนาด n x n โดยที่ dp[i][j] แทนความยาวของ LPS ของสตริงย่อยจากตำแหน่ง i ถึง j
ทุกตัวอักษรเป็น palindrome ความยาว 1: dp[i][i] = 1
ถ้าตัวอักษรที่ i และ j เหมือนกัน: dp[i][j] = 2 + dp[i+1][j-1]
ถ้าไม่เหมือน: dp[i][j] = max(dp[i+1][j], dp[i][j-1])
*/
int longestPalindromeSubseq(char* s) {
    int n = strlen(s);
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        dp[i] = (int*)calloc(n, sizeof(int));
        dp[i][i] = 1;
    }
    
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i+1][j-1];
            } else {
                dp[i][j] = dp[i+1][j] > dp[i][j-1] ? dp[i+1][j] : dp[i][j-1];
            }
        }
    }
    
    int result = dp[0][n-1];
    for (int i = 0; i < n; ++i) free(dp[i]);
    free(dp);
    return result;
}