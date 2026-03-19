int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int count = 0;
    
    // สร้าง prefix sum arrays
    int** prefixX = (int**)malloc((m + 1) * sizeof(int*));
    int** prefixY = (int**)malloc((m + 1) * sizeof(int*));
    
    for (int i = 0; i <= m; i++) {
        prefixX[i] = (int*)calloc(n + 1, sizeof(int));
        prefixY[i] = (int*)calloc(n + 1, sizeof(int));
    }
    
    // คำนวณ prefix sum
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int valX = (grid[i][j] == 'X') ? 1 : 0;
            int valY = (grid[i][j] == 'Y') ? 1 : 0;
            
            prefixX[i + 1][j + 1] = valX + prefixX[i][j + 1] + prefixX[i + 1][j] - prefixX[i][j];
            prefixY[i + 1][j + 1] = valY + prefixY[i][j + 1] + prefixY[i + 1][j] - prefixY[i][j];
        }
    }
    
    // ตรวจสอบ submatrix ทุกอันที่เริ่มจาก (0,0)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int xCount = prefixX[i + 1][j + 1];
            int yCount = prefixY[i + 1][j + 1];
            
            if (xCount > 0 && xCount == yCount) {
                count++;
            }
        }
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i <= m; i++) {
        free(prefixX[i]);
        free(prefixY[i]);
    }
    free(prefixX);
    free(prefixY);
    
    return count;
}