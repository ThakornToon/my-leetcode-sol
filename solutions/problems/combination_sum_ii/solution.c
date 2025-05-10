/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) { 
    return *(int *)a - *(int *)b; 
}

void backtrack(int *candidates, int candidatesSize, int *store, int start, int target, int **result, int *returnSize, int **returnColumnSizes, int count){
    if (target == 0) {
        result[(*returnSize)] = (int *)malloc(count * sizeof(int));
        for (int i = 0; i < count; i++) {
            result[(*returnSize)][i] = store[i];
        }
        (*returnColumnSizes)[(*returnSize)] = count;
        (*returnSize)++;
        return;
    }
    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i-1]) {
            continue;
        }
        if (candidates[i] > target){
            return;
        }
        else{
            store[count] = candidates[i];
            backtrack(candidates, candidatesSize, store, i+1, target-candidates[i], result, returnSize, returnColumnSizes, count+1);
        }
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int **result = (int **)malloc(50 * sizeof(int*));
    *returnColumnSizes = (int *)malloc(50 * sizeof(int));
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int *store = (int *)malloc(30 * sizeof(int));
    backtrack(candidates, candidatesSize, store, 0, target, result, returnSize, returnColumnSizes, 0);
    return result;
}