/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int m = matrixSize;        // จำนวนแถวเดิม
    int n = matrixColSize[0];  // จำนวนคอลัมน์เดิม
    
    // สร้าง matrix ผลลัพธ์ขนาด n × m
    int** result = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    
    // สร้างแต่ละแถวของผลลัพธ์
    for (int i = 0; i < n; i++) {
        result[i] = (int*)malloc(m * sizeof(int));
        (*returnColumnSizes)[i] = m;
    }
    
    // คำนวณ transpose
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    
    *returnSize = n;  // จำนวนแถวของผลลัพธ์ = จำนวนคอลัมน์เดิม
    return result;
}