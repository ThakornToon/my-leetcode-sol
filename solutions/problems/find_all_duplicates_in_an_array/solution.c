/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0) {
            result[(*returnSize)++] = index + 1;
        } else {
            nums[index] *= -1;
        }
    }
    
    return result;
}