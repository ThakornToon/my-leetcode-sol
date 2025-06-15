/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int left = 1;
    for (int i = 0; i < numsSize; i++) {
        res[i] = 1;
        res[i] *= left;
        left *= nums[i];
    }
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        res[i] *= right;
        right *= nums[i];
    }
    return res;
}