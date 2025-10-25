/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// ฟังก์ชันตรวจสอบว่าสามารถเป็นจำนวนเต็มได้หรือไม่
int isValidInteger(char* s, int len) {
    if (len > 1 && s[0] == '0') return 0;
    return 1;
}

// ฟังก์ชันตรวจสอบว่าสามารถเป็นส่วนทศนิยมได้หรือไม่
int isValidDecimal(char* s, int len) {
    if (s[len - 1] == '0') return 0;
    return 1;
}

// สร้างตัวเลขที่เป็นไปได้
char** makeNumbers(char* s, int len, int* count) {
    char** options = malloc(100 * sizeof(char*));
    *count = 0;
    
    // กรณีไม่มีจุดทศนิยม
    if (isValidInteger(s, len)) {
        options[*count] = malloc(len + 1);
        strncpy(options[*count], s, len);
        options[*count][len] = '\0';
        (*count)++;
    }
    
    // กรณีมีจุดทศนิยม
    for (int i = 1; i < len; i++) {
        if (isValidInteger(s, i) && isValidDecimal(s + i, len - i)) {
            options[*count] = malloc(len + 2);
            strncpy(options[*count], s, i);
            options[*count][i] = '.';
            strncpy(options[*count] + i + 1, s + i, len - i);
            options[*count][len + 1] = '\0';
            (*count)++;
        }
    }
    
    return options;
}

// ฟังก์ชันหลัก
char** ambiguousCoordinates(char* s, int* returnSize) {
    char** result = malloc(1000 * sizeof(char*));
    *returnSize = 0;
    
    int len = strlen(s);
    // เก็บส่วนตัวเลข
    char* numbers = malloc(len - 1);
    strncpy(numbers, s + 1, len - 2);
    numbers[len - 2] = '\0';
    int numLen = len - 2;
    
    for (int i = 1; i < numLen; i++) {
        // แบ่งส่วนตัวเลข
        int leftCount, rightCount;
        char** leftOptions = makeNumbers(numbers, i, &leftCount);
        char** rightOptions = makeNumbers(numbers + i, numLen - i, &rightCount);
        
        for (int j = 0; j < leftCount; j++) {
            for (int k = 0; k < rightCount; k++) {
                result[*returnSize] = malloc(100);
                sprintf(result[*returnSize], "(%s, %s)", leftOptions[j], rightOptions[k]);
                (*returnSize)++;
            }
        }
        
        // คืนหน่วยความจำ
        for (int j = 0; j < leftCount; j++) free(leftOptions[j]);
        for (int j = 0; j < rightCount; j++) free(rightOptions[j]);
        free(leftOptions);
        free(rightOptions);
    }
    
    free(numbers);
    return result;
}