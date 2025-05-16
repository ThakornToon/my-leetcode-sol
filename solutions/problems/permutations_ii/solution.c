/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int* nums, int x, int y) {
    int temp = nums[x];
    nums[x] = nums[y];
    nums[y] = temp;
}

int factorial(int n) {
    int res;
    for (res = 1; n > 1; n--) {
        res *= n;
    }
    return res;
}

int cmp(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

void backtrack(int** result, int* nums, int numsSize, int start, int* count) {
    if (start == numsSize) {
        result[*count] = (int *)malloc(numsSize*sizeof(int));
        memcpy(result[(*count)++], nums, numsSize*sizeof(int));
        return;
    }
    int hash_check[21] = {0};
    for (int i = start; i < numsSize; i++) {
        if (hash_check[nums[i] + 10]) continue;
        hash_check[nums[i] + 10] = 1;
        swap(nums, start, i);
        backtrack(result, nums, numsSize, start + 1, count);
        swap(nums, start, i);
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int count = 1;
    int dividend = 1;
    for (int i = 0; i < numsSize; i++)
    { 
        if (i+1 < numsSize && (nums[i] == nums[i+1]))
            count++;
        else
        {
            dividend *= factorial(count);
            count = 1;
        }
    }
    int fact = factorial(numsSize) / dividend;
    int** result = (int**)malloc(fact*sizeof(int *));
    int* temp = (int*)malloc(numsSize*sizeof(int));
    *returnColumnSizes = (int*)malloc(fact * sizeof(int));
    for(int i=0; i<fact; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    *returnSize = fact;
    fact = 0;
    backtrack(result, nums, numsSize, 0, &fact);
    free(temp);
    return result;
}