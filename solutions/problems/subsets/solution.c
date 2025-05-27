/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

void findSubsets(int* nums, int** subsets, int currIndex, int numsSize, int* returnSize, int** returnColumnSizes) {

    if (currIndex > numsSize) {
        return;
    }
    int currentSize = *returnSize;

    for (int i = 0; i < currentSize; i++) { //วนแต่ละคำตอบเก่าเพื่อเติมลงไป
        int newSize = (*returnColumnSizes)[i] + 1;
        int* set = malloc(sizeof(int) * newSize);
        memcpy(set, subsets[i], (*returnColumnSizes)[i] * sizeof(int)); //ก๊อปตัวเก่ามาเพื่อต่อเติม
        set[(*returnColumnSizes)[i]] = nums[currIndex - 1];
        // insert new subset into array of sets
        subsets[*returnSize] = set;
        (*returnColumnSizes)[(*returnSize)++] = newSize;
    }

    findSubsets(nums, subsets, currIndex + 1, numsSize, returnSize, returnColumnSizes);
    
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int N = 1;
    for(int i = 0; i < numsSize; i++){
        N *= 2;
    }
    int** subsets = malloc(sizeof(int*) * N);
    int* emptySet = malloc(sizeof(int));
    int* columnSizes = malloc(sizeof(int) * N);
    *returnSize = 0;
    columnSizes[0] = 0;
    *returnColumnSizes = columnSizes;
    subsets[(*returnSize)++] = emptySet;
    findSubsets(nums, subsets, 1, numsSize, returnSize, returnColumnSizes);
    return subsets;
}