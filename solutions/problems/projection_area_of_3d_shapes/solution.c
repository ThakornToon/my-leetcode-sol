int projectionArea(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int xy = 0, xz = 0, yz = 0;
    
    // สร้าง array สำหรับเก็บค่าสูงสุดของแต่ละ column
    int* colMax = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        colMax[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        int rowMax = 0;
        
        for (int j = 0; j < n; j++) {
            // XY-plane
            if (grid[i][j] > 0) {
                xy++;
            }
            
            // row max
            if (grid[i][j] > rowMax) {
                rowMax = grid[i][j];
            }
            
            // column max
            if (grid[i][j] > colMax[j]) {
                colMax[j] = grid[i][j];
            }
        }
        
        yz += rowMax;
    }
    
    // รวม column max
    for (int j = 0; j < n; j++) {
        xz += colMax[j];
    }
    
    free(colMax);
    return xy + xz + yz;
}