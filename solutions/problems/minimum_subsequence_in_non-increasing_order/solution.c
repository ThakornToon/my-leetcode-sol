/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a;  // เรียงจากมากไปน้อย
}

int* minSubsequence(int* nums, int numsSize, int* returnSize) {
    // เรียงจากมากไปน้อย
    qsort(nums, numsSize, sizeof(int), compare);
    
    // คำนวณผลรวมทั้งหมด
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }
    
    // หา subsequence
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;
    int subSum = 0;
    
    for (int i = 0; i < numsSize; i++) {
        subSum += nums[i];
        result[(*returnSize)++] = nums[i];
        if (subSum > totalSum - subSum) {
            break;
        }
    }
    
    return result;
}