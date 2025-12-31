/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    // 1. เรียงลำดับ array
    qsort(arr, arrSize, sizeof(int), compare);
    
    // 2. หาความแตกต่างน้อยที่สุด
    // 3. นับจำนวนคู่ที่มีความแตกต่าง = minDiff
    int minDiff = INT_MAX;
    int pairCount = 0;
    for (int i = 1; i < arrSize; i++) {
        int diff = arr[i] - arr[i-1];
        if (diff < minDiff) {
            minDiff = diff;
            pairCount = 0;
        }
        if (arr[i] - arr[i-1] == minDiff) {
            pairCount++;
        }
    }
    
    // 4. จอง memory สำหรับผลลัพธ์
    int** result = (int**)malloc(pairCount * sizeof(int*));
    *returnColumnSizes = (int*)malloc(pairCount * sizeof(int));
    *returnSize = pairCount;
    
    // 5. เก็บคู่ทั้งหมด
    int idx = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i-1] == minDiff) {
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = arr[i-1];
            result[idx][1] = arr[i];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }
    
    return result;
}