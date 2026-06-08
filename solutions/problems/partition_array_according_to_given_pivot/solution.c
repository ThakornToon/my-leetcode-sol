/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    // จองหน่วยความจำสำหรับผลลัพธ์
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    int index = 0;
    
    // Pass 1: เก็บตัวเลขที่น้อยกว่า pivot
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < pivot) {
            result[index++] = nums[i];
        }
    }
    
    // Pass 2: เก็บตัวเลขที่เท่ากับ pivot
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == pivot) {
            result[index++] = nums[i];
        }
    }
    
    // Pass 3: เก็บตัวเลขที่มากกว่า pivot
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > pivot) {
            result[index++] = nums[i];
        }
    }
    
    return result;
}