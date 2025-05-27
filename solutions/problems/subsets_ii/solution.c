/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void findSubsets(int* nums, int** subsets, int currIndex, int numsSize, int* returnSize, int** returnColumnSizes) {
    static int start = 0;
    if (currIndex > numsSize) {
        start = 0;
        return;
    }
    int currentSize = *returnSize;
    int prev_start = start;
    start = currentSize;

    for (int i = 0; i < currentSize; i++) {
        if (currIndex > 1 && nums[currIndex-1] == nums[currIndex-2] && i < prev_start) {
            continue;
        }
        int newSize = (*returnColumnSizes)[i] + 1;
        int* set = malloc(sizeof(int) * newSize);
        memcpy(set, subsets[i], (*returnColumnSizes)[i] * sizeof(int));
        set[(*returnColumnSizes)[i]] = nums[currIndex - 1];

        subsets[*returnSize] = set;
        (*returnColumnSizes)[(*returnSize)++] = newSize;
    }

    findSubsets(nums, subsets, currIndex + 1, numsSize, returnSize, returnColumnSizes);
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int n = 1;
    for(int i = 0; i < numsSize; i++){
        n *= 2;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int** subsets = (int**)malloc(sizeof(int*) * n);
    int* emptySet = (int*)malloc(0);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    *returnSize = 0;
    *returnColumnSizes[0] = 0;
    subsets[(*returnSize)++] = emptySet;
    findSubsets(nums, subsets, 1, numsSize, returnSize, returnColumnSizes);
    return subsets;
}