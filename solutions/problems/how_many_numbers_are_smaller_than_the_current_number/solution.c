/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    // สร้าง sorted copy
    int* sorted = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        sorted[i] = nums[i];
    }
    qsort(sorted, numsSize, sizeof(int), compare);
    
    // binary search หาตำแหน่งแรกของ nums[i]
    for (int i = 0; i < numsSize; i++) {
        int left = 0, right = numsSize - 1;
        int pos = numsSize;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (sorted[mid] >= nums[i]) {
                pos = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        result[i] = pos;
    }
    
    free(sorted);
    return result;
}