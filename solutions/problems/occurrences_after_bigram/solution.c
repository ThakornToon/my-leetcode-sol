/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findOcurrences(char* text, char* first, char* second, int* returnSize) {
    char** words = malloc(1000 * sizeof(char*));
    int wordCount = 0;
    
    char* token = strtok(text, " ");
    while (token != NULL) {
        words[wordCount] = malloc(strlen(token) + 1);
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, " ");
    }
    
    char** result = malloc(1000 * sizeof(char*));
    int resultCount = 0;
    
    for (int i = 0; i < wordCount - 2; i++) {
        if (strcmp(words[i], first) == 0 && strcmp(words[i + 1], second) == 0) {
            result[resultCount] = malloc(strlen(words[i + 2]) + 1);
            strcpy(result[resultCount], words[i + 2]);
            resultCount++;
        }
    }
    
    // Clean up words array
    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
    free(words);
    
    *returnSize = resultCount;
    return result;
}