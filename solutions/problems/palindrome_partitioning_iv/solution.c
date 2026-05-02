bool checkPartitioning(char* s) {
    int n = strlen(s);
    if (n < 3) return false;
    
    // สร้างตาราง palindrome
    bool** isPal = (bool**)malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++) {
        isPal[i] = (bool*)calloc(n, sizeof(bool));
        isPal[i][i] = true;

        // ความยาว 2
        if (i < n - 1 && s[i] == s[i + 1]) {
            isPal[i][i + 1] = true;
        }
    }
        
    // ความยาว >= 3
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && isPal[i + 1][j - 1]) {
                isPal[i][j] = true;
            }
        }
    }
    
    // ลองทุกตำแหน่งตัด
    for (int i = 0; i < n - 2; i++) {
        if (!isPal[0][i]) continue;
        
        for (int j = i + 1; j < n - 1; j++) {
            if (isPal[i + 1][j] && isPal[j + 1][n - 1]) {
                // คืนหน่วยความจำ
                for (int k = 0; k < n; k++) free(isPal[k]);
                free(isPal);
                return true;
            }
        }
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i < n; i++) free(isPal[i]);
    free(isPal);
    
    return false;
}