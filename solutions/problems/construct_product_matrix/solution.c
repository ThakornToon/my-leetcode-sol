/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MOD 12345

int** constructProductMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = gridColSize[0];
    
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }
    
    // สร้าง result matrix และ initialize ด้วย 1
    int** result = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            result[i][j] = 1;
        }
    }
    
    // Forward pass: product of all elements before current
    long long prod = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = (result[i][j] * prod) % MOD;
            prod = (prod * (grid[i][j] % MOD)) % MOD;
        }
    }
    
    // Backward pass: multiply by product of all elements after current
    prod = 1;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            result[i][j] = (result[i][j] * prod) % MOD;
            prod = (prod * (grid[i][j] % MOD)) % MOD;
        }
    }
    
    return result;
}