/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// น้อยไปมาก
int compareLen(const void* a, const void* b) {
    return strlen(*(char**)a) - strlen(*(char**)b);
}

char** stringMatching(char** words, int wordsSize, int* returnSize) {
    // สร้าง copy และเรียงตามความยาว
    char** sorted = (char**)malloc(wordsSize * sizeof(char*));
    for (int i = 0; i < wordsSize; i++) {
        sorted[i] = words[i];
    }
    qsort(sorted, wordsSize, sizeof(char*), compareLen);
    
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (strstr(sorted[j], sorted[i]) != NULL) {
                result[*returnSize] = (char*)malloc((strlen(sorted[i]) + 1) * sizeof(char));
                strcpy(result[*returnSize], sorted[i]);
                (*returnSize)++;
                break;
            }
        }
    }
    
    free(sorted);
    return result; 
}