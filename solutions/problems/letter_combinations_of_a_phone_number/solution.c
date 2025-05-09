/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

const char* keypad[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(char** result, int* resultSize, char* combination, char* digits, int index) {
    if (digits[index] == '\0') {
        result[*resultSize] = strdup(combination);
        (*resultSize)++;
        return;
    }
    
    const char* letters = keypad[digits[index] - '2'];
    for (int i = 0; letters[i] != '\0'; i++) {
        int len = strlen(combination);
        combination[len] = letters[i];
        combination[len + 1] = '\0';
        backtrack(result, resultSize, combination, digits, index + 1);
        combination[len] = '\0';
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    if (*digits == '\0') {
        *returnSize = 0;
        return NULL;
    }
    char** result = (char**)malloc(256 * sizeof(char*));
    *returnSize = 0;
    char combination[5] = "";
    backtrack(result, returnSize, combination, digits, 0);
    return result;
}