/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
void backtrack(int k, int n, int** res, int* store, int start, int** returnColumnSizes, int* returnSize, int count) {
    if (k == count) {
        if (n != 0) {
            return;
        }
        res[*returnSize] = (int*)malloc(k * sizeof(int));
        memcpy(res[*returnSize], store, k * sizeof(int));
        (*returnColumnSizes)[*returnSize] = count;
        (*returnSize)++;
        return;
    }
    for (int i = start; i <= 9; i++) {
        if (n - i < 0) {
            return;
        }
        store[count] = i;
        backtrack(k, n - i, res, store, i + 1, returnColumnSizes, returnSize, count + 1);
    }
}
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(100 * sizeof(int));
    int** res = (int**)malloc(100 * sizeof(int*));
    int* store = (int*)malloc(k * sizeof(int));
    backtrack(k, n, res, store, 1, returnColumnSizes, returnSize, 0);
    free(store);
    res = (int**)realloc(res, (*returnSize) * sizeof(int*));
    *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*returnSize) * sizeof(int*));
    return res;
}