/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    // ผลลัพธ์มีขนาดมากสุด 2*n (push+pop)
    char** result = (char**)malloc(2 * n * sizeof(char*));
    *returnSize = 0;
    
    int targetIdx = 0;
    
    for (int i = 1; i <= n && targetIdx < targetSize; i++) {
        // Push operation
        result[*returnSize] = (char*)malloc(5 * sizeof(char));
        strcpy(result[*returnSize], "Push");
        (*returnSize)++;
        
        // ถ้าค่าไม่ตรง target ให้ pop
        if (target[targetIdx] != i) {
            result[*returnSize] = (char*)malloc(4 * sizeof(char));
            strcpy(result[*returnSize], "Pop");
            (*returnSize)++;
        } else {
            targetIdx++;
        }
    }
    
    return result;
}