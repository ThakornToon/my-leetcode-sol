int countSubstrings(char* s) {
    int n = strlen(s);
    if (n == 1) return 1;
    int sum = 0;
    int** table = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        table[i] = (int*)calloc(n, sizeof(int));
    }
    
    // Palindromic substring ความยาว 1
    for (int i = 0; i < n; i++) {
        table[i][i] = 1;
        sum++;
    }
    
    // Palindromic substring ความยาว 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            table[i][i + 1] = 1;
            sum++;
        }
    }
    
    // Palindromic substring ความยาว 3 ขึ้นไป
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && table[i + 1][j - 1]) {
                table[i][j] = 1;
                sum++;
            }
        }
    }
    
    // คืน memory
    for (int i = 0; i < n; i++) {
        free(table[i]);
    }
    free(table);
    
    return sum;
}