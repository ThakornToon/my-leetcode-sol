/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = gridColSize[0];
    int total = m * n;
    
    // ลด k ให้อยู่ในช่วง 0 ถึง total-1
    k = k % total;
    if (k == 0) {
        // ถ้า k=0 ให้คืนค่า grid เดิม (copy)
        *returnSize = m;
        *returnColumnSizes = (int*)malloc(m * sizeof(int));
        int** result = (int**)malloc(m * sizeof(int*));
        
        for (int i = 0; i < m; i++) {
            (*returnColumnSizes)[i] = n;
            result[i] = (int*)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) {
                result[i][j] = grid[i][j];
            }
        }
        return result;
    }
    
    // สร้าง grid ผลลัพธ์
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    int** result = (int**)malloc(m * sizeof(int*));
    
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
        result[i] = (int*)malloc(n * sizeof(int));
    }
    
    // ใส่ค่าในตำแหน่งใหม่
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // คำนวณตำแหน่งใหม่
            int newIndex = (i * n + j + k) % total;
            int newRow = newIndex / n;
            int newCol = newIndex % n;
            
            result[newRow][newCol] = grid[i][j];
        }
    }
    
    return result;
}