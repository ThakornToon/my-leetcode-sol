bool checkValidGrid(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    
    // เก็บตำแหน่งของแต่ละตัวเลข (0 ถึง n*n-1)
    int* posX = (int*)malloc(n * n * sizeof(int));
    int* posY = (int*)malloc(n * n * sizeof(int));
    
    // หาตำแหน่งของแต่ละตัวเลข
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = grid[i][j];
            posX[num] = i;
            posY[num] = j;
        }
    }
    
    // ตรวจสอบว่าต้องเริ่มจากตำแหน่ง (0,0)
    if (posX[0] != 0 || posY[0] != 0) {
        free(posX);
        free(posY);
        return false;
    }
    
    // ตรวจสอบแต่ละขั้นตอน
    for (int step = 1; step < n * n; step++) {
        int x1 = posX[step - 1];
        int y1 = posY[step - 1];
        int x2 = posX[step];
        int y2 = posY[step];
        
        int dx = abs(x1 - x2);
        int dy = abs(y1 - y2);
        
        // Knight move ต้องเป็น (1,2) หรือ (2,1)
        if (!((dx == 1 && dy == 2) || (dx == 2 && dy == 1))) {
            free(posX);
            free(posY);
            return false;
        }
    }
    
    free(posX);
    free(posY);
    return true;
}