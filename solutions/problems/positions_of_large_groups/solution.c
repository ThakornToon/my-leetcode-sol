/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);
    int** result = (int**)malloc(n * sizeof(int*)); // maximum possible groups
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    *returnSize = 0;
    
    int start = 0;
    for (int i = 1; i <= n; i++) {
        if (i == n || s[i] != s[start]) {
            int length = i - start;
            if (length >= 3) {
                result[*returnSize] = (int*)malloc(2 * sizeof(int));
                result[*returnSize][0] = start;
                result[*returnSize][1] = i - 1;
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
            }
            start = i;
        }
    }
    
    return result;
}