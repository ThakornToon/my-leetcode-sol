/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int* candidates, int candidatesSize, int target, int start, int count, int** result, int* store, int* returnSize, int** returnColumnSizes){
    if (target == 0){
        result[*returnSize] = (int*)malloc(count * sizeof(int));
        memcpy(result[*returnSize], store, count*sizeof(int));
        (*returnColumnSizes)[*returnSize] = count;
        (*returnSize)++;
        return;
    }
    for (int i = start;  i < candidatesSize; i++){
        if (target - candidates[i] >= 0){
            store[count] = candidates[i];
            backtrack(candidates, candidatesSize, target-candidates[i], i, count+1, result, store, returnSize, returnColumnSizes);
        }
    }
    
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int** result = (int**)malloc(150 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(150 * sizeof(int));
    int* store = (int*)malloc(target * sizeof(int));
    backtrack(candidates, candidatesSize, target, 0, 0, result, store, returnSize, returnColumnSizes);
    free(store);
    return result;
}