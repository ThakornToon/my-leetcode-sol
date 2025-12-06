/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findAndReplacePattern(char** words, int wordsSize, char* pattern, int* returnSize) {
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        int len = strlen(word);
        
        if (len != strlen(pattern)) {
            continue;
        }
        
        // สร้าง mapping arrays
        char patternToWord[26] = {0};
        char wordToPattern[26] = {0};
        int isValid = 1;
        
        for (int j = 0; j < len; j++) {
            char p = pattern[j];
            char w = word[j];
            
            // ตรวจสอบ mapping จาก pattern ไป word
            if (patternToWord[p - 'a'] == 0) {
                patternToWord[p - 'a'] = w;
            } else if (patternToWord[p - 'a'] != w) {
                isValid = 0;
                break;
            }
            
            // ตรวจสอบ mapping จาก word ไป pattern
            if (wordToPattern[w - 'a'] == 0) {
                wordToPattern[w - 'a'] = p;
            } else if (wordToPattern[w - 'a'] != p) {
                isValid = 0;
                break;
            }
        }
        
        if (isValid) {
            result[*returnSize] = (char*)malloc((len + 1) * sizeof(char));
            strcpy(result[*returnSize], word);
            (*returnSize)++;
        }
    }
    
    return result;
}