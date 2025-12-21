int isPredecessor(const char* a, const char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    
    if (lenA + 1 != lenB) return 0;
    
    int i = 0, j = 0;
    int diffFound = 0;
    
    while (i < lenA && j < lenB) {
        if (a[i] == b[j]) {
            i++;
            j++;
        } else {
            if (diffFound) return 0;
            diffFound = 1;
            j++;  // skip one character in b
        }
    }
    
    return 1;
}

int compareStrings(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;
    return strlen(str1) - strlen(str2);
}

int longestStrChain(char** words, int wordsSize) {
    // เรียงตามความยาวสตริง
    qsort(words, wordsSize, sizeof(char*), compareStrings);
    
    // dp[i] = longest chain ending at words[i]
    int* dp = (int*)malloc(wordsSize * sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        dp[i] = 1;  // ตัวมันเองแค่ตัวเดียว
    }
    
    int maxLength = 1;
    
    // ตรวจสอบแต่ละคำกับคำก่อนหน้าที่สั้นกว่า
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (isPredecessor(words[j], words[i]) && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                if (dp[i] > maxLength) {
                    maxLength = dp[i];
                }
            }
        }
    }
    
    free(dp);
    return maxLength;
}