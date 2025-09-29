/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 */

void backtrack(int* nums, int numsSize, int start, int* current, int* currentSize, 
               int** result, int* returnSize, int** returnColumnSizes) {
    
    if (*currentSize >= 2) {
        // เพิ่ม subsequence ลงในผลลัพธ์
        result[*returnSize] = (int*)malloc((*currentSize) * sizeof(int));
        for (int i = 0; i < *currentSize; i++) {
            result[*returnSize][i] = current[i];
        }
        (*returnColumnSizes)[*returnSize] = *currentSize;
        (*returnSize)++;
    }
    
    int used[201] = {0}; // เนื่องจาก nums[i] ∈ [-100, 100]
    
    for (int i = start; i < numsSize; i++) {
        // ตรวจสอบ duplicates
        if (used[nums[i] + 100]) continue;
        // ตรวจสอบ non-decreasing
        if (*currentSize > 0 && nums[i] < current[*currentSize - 1]) continue;
        
        used[nums[i] + 100] = 1;
        current[*currentSize] = nums[i];
        (*currentSize)++;
        
        backtrack(nums, numsSize, i + 1, current, currentSize, result, returnSize, returnColumnSizes);
        
        (*currentSize)--;
    }
}

int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // กำหนดขนาดสูงสุดเพื่อป้องกัน memory issues
    int maxResult = 40000;
    int** result = (int**)malloc(maxResult * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxResult * sizeof(int));
    *returnSize = 0;
    
    int* current = (int*)malloc(numsSize * sizeof(int));
    int currentSize = 0;
    
    backtrack(nums, numsSize, 0, current, &currentSize, result, returnSize, returnColumnSizes);
    
    free(current);
    return result;
}
