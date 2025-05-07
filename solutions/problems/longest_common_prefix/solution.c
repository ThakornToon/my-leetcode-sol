char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {return "";}
    int min = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < min) {
            min = len;
        }
    }
    char* prefix = (char*)malloc(sizeof(char) * (min + 1)); // รวม \0
    int i;
    for (i = 0; i < min; i++) {
        char ch = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != ch) {
                prefix[i] = '\0';
                return prefix;
            }
        }
        prefix[i] = ch;
    }
    prefix[i] = '\0';
    return prefix;
}