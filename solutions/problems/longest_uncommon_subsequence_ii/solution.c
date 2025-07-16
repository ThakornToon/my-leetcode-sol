int isSubsequence(const char* a, const char* b) {
    int i = 0, j = 0;
    while (a[i] != '\0' && b[j] != '\0') {
        if (a[i] == b[j]) {
            i++;
        }
        j++;
    }
    return a[i] == '\0';
}

int compare(const void* a, const void* b) {
    int len_a = strlen(*(const char**)a);
    int len_b = strlen(*(const char**)b);
    return (len_a < len_b) - (len_a > len_b);
}

int findLUSlength(char** strs, int strsSize) {
    qsort(strs, strsSize, sizeof(char*), compare);
    
    for (int i = 0; i < strsSize; ++i) {
        int isUncommon = 1;
        for (int j = 0; j < strsSize; ++j) {
            if (i == j) continue;
            if (isSubsequence(strs[i], strs[j])) {
                isUncommon = 0;
                break;
            }
        }
        if (isUncommon) {
            return strlen(strs[i]);
        }
    }
    
    return -1;
}