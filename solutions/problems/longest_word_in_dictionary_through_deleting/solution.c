int isSubsequence(const char* word, const char* s) {
    int i = 0, j = 0;
    while (word[i] != '\0' && s[j] != '\0') {
        if (word[i] == s[j]) {
            i++;
        }
        j++;
    }
    return word[i] == '\0';
}

int compare(const void* a, const void* b) {
    const char* str_a = *(const char**)a;
    const char* str_b = *(const char**)b;
    int len_a = strlen(str_a);
    int len_b = strlen(str_b);
    
    if (len_a != len_b) {
        return len_b - len_a;
    }
    return strcmp(str_a, str_b);
}

char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    // เรียงตามความยาวจากมากไปน้อย และตามลำดับพจนานุกรม
    qsort(dictionary, dictionarySize, sizeof(char*), compare);
    
    for (int i = 0; i < dictionarySize; i++) {
        if (isSubsequence(dictionary[i], s)) {
            return dictionary[i];
        }
    }
    
    return "";
}