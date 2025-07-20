/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
    // ตรวจสอบว่าแปลงเป็น 2D array ได้หรือไม่
    if (originalSize != m * n) {
        *returnSize = 0;
        return NULL;
    }
    
    // จอง memory สำหรับ array 2D
    int** result = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    *returnSize = m;
    
    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        
        // คัดลอกข้อมูลจาก original
        for (int j = 0; j < n; j++) {
            result[i][j] = original[i * n + j];
        }
    }
    
    return result;
}