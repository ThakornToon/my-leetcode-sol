/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    
    // เก็บค่าต่ำสุดในแต่ละแถวและ col ที่พบ
    int* rowMins = (int*)malloc(m * sizeof(int));
    int* minCols = (int*)malloc(m * sizeof(int));
    
    for (int i = 0; i < m; i++) {
        rowMins[i] = matrix[i][0];
        minCols[i] = 0;
        
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] < rowMins[i]) {
                rowMins[i] = matrix[i][j];
                minCols[i] = j;
            }
        }
    }
    
    // ตรวจสอบว่าค่าต่ำสุดในแถวเป็นค่าสูงสุดในคอลัมน์หรือไม่
    int* result = (int*)malloc(m * sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < m; i++) {
        int candidate = rowMins[i];
        int col = minCols[i];
        bool isMax = true;
        
        for (int r = 0; r < m; r++) {
            if (matrix[r][col] > candidate) {
                isMax = false;
                break;
            }
        }
        
        if (isMax) {
            result[(*returnSize)++] = candidate;
        }
    }
    
    free(rowMins);
    free(minCols);
    
    return result;
}