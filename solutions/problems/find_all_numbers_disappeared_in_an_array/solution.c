/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* nums, int i, int j) {
    int temp = nums[i - 1];
    nums[i - 1] = i;
    nums[j] = temp;
}
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            swap(nums, nums[i], i);
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            res[(*returnSize)++] = i + 1;
        }
    }
    return res;
}