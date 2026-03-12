/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m = matSize;
    int n = matColSize[0];
    
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }
    
    // สร้าง prefix sum array
    int** prefix = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        prefix[i] = (int*)calloc(n + 1, sizeof(int));
    }
    
    // คำนวณ prefix sum ตั้งแต่ (0,0) ถึง (i,j)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
        }
    }
    
    // สร้างผลลัพธ์
    int** result = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(n * sizeof(int));
        
        for (int j = 0; j < n; j++) {
            // คำนวณขอบเขตของ window
            int r1 = MAX(0, i - k);
            int c1 = MAX(0, j - k);
            int r2 = MIN(m - 1, i + k);
            int c2 = MIN(n - 1, j + k);
            
            // ใช้ prefix sum หาผลรวมในช่วง [r1..r2, c1..c2]
            result[i][j] = prefix[r2 + 1][c2 + 1] - prefix[r1][c2 + 1] - 
                          prefix[r2 + 1][c1] + prefix[r1][c1];
        }
    }
    
    // คืนหน่วยความจำ prefix
    for (int i = 0; i <= m; i++) {
        free(prefix[i]);
    }
    free(prefix);
    
    return result;
}