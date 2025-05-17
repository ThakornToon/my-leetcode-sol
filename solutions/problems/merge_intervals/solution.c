/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    int* intA = *(int**)a;
    int* intB = *(int**)b;
    return intA[0] - intB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int** res = malloc(intervalsSize * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    for(int i=0; i<intervalsSize; ++i) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if(*returnSize==0 || (res[*returnSize-1][1] < start)) {
            res[*returnSize] = malloc(2*sizeof(int));
            res[*returnSize][0] = start;
            res[*returnSize][1] = end;
            (*returnColumnSizes)[*returnSize] = 2;
            ++(*returnSize);
        } 
        else {    
            if (res[*returnSize - 1][1] < end) {
                res[*returnSize-1][1] = end;
            }
        }
    }
    return res;
}