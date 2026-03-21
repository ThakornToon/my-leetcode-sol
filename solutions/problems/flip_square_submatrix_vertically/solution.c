/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y, int k, int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = gridColSize[0];
    
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }
    
    // ตรวจสอบว่าขอบเขตถูกต้อง
    if (x < 0 || x + k > m || y < 0 || y + k > n) {
        // ถ้าขอบเขตไม่ถูกต้อง คืนค่า grid เดิม
        int** result = (int**)malloc(m * sizeof(int*));
        for (int i = 0; i < m; i++) {
            result[i] = (int*)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) {
                result[i][j] = grid[i][j];
            }
        }
        return result;
    }
    
    // สร้าง matrix ผลลัพธ์ (copy จาก grid)
    int** result = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            result[i][j] = grid[i][j];
        }
    }
    
    // Flip submatrix แนวตั้ง
    for (int row = 0; row < k / 2; row++) {
        int topRow = x + row;
        int bottomRow = x + k - 1 - row;
        
        for (int col = 0; col < k; col++) {
            int actualCol = y + col;
            
            // สลับค่า
            int temp = result[topRow][actualCol];
            result[topRow][actualCol] = result[bottomRow][actualCol];
            result[bottomRow][actualCol] = temp;
        }
    }
    
    return result;
}