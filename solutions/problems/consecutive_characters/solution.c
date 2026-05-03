int maxPower(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;
    
    int maxLen = 1;
    int currentLen = 1;
    
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            currentLen++;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        } else {
            currentLen = 1;
        }
    }
    
    return maxLen;
}