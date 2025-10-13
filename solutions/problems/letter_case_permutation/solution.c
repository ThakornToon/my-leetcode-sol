/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char* s, int index, char* current, char** result, int* returnSize) {
    // Base case: ถึงสุด string แล้ว
    if (index == strlen(s)) {
        current[index] = '\0';
        result[*returnSize] = malloc((strlen(s) + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }
    
    char c = s[index];
    
    // ถ้าเป็นตัวเลข เพิ่มเลย
    if (isdigit(c)) {
        current[index] = c;
        backtrack(s, index + 1, current, result, returnSize);
    } else {
        // เป็นตัวอักษร สร้าง 2 กรณี
        current[index] = tolower(c);
        backtrack(s, index + 1, current, result, returnSize);
        
        current[index] = toupper(c);
        backtrack(s, index + 1, current, result, returnSize);
    }
}

char** letterCasePermutation(char* s, int* returnSize) {
    int n = strlen(s);
    
    // คำนวณจำนวนผลลัพธ์
    int letterCount = 0;
    for (int i = 0; i < n; i++) {
        if (isalpha(s[i])) letterCount++;
    }
    int total = 1 << letterCount; // 2^letterCount
    
    // จอง memory
    char** result = malloc(total * sizeof(char*));
    char* current = malloc((n + 1) * sizeof(char));
    *returnSize = 0;
    
    backtrack(s, 0, current, result, returnSize);
    
    free(current);
    return result;
}