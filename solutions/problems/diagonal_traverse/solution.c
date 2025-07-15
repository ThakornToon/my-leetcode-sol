/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int m = matSize, n = *matColSize;
    int* result = (int*)malloc(m * n * sizeof(int));
    *returnSize = m * n;
    
    int row = 0, col = 0;
    int direction = 1; // 1 for upward, -1 for downward
    
    for (int i = 0; i < m * n; i++) {
        result[i] = mat[row][col];
        
        if (direction == 1) {
            if (col == n - 1) {
                row++;
                direction = -1;
            } else if (row == 0) {
                col++;
                direction = -1;
            } else {
                row--;
                col++;
            }
        } else {
            if (row == m - 1) {
                col++;
                direction = 1;
            } else if (col == 0) {
                row++;
                direction = 1;
            } else {
                row++;
                col--;
            }
        }
    }
    
    return result;
}