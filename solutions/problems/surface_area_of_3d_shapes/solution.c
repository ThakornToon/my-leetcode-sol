int max(int a, int b) {
    return a > b ? a : b;
}

int surfaceArea(int** grid, int gridSize, int* gridColSize) {
    int surface = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j] > 0) {
                // บน: เห็นได้เสมอถ้ามีกล่อง
                surface += 1;
                // เห็นได้เสมอถ้ามีกล่อง  
                surface += 1;
                
                // หน้า: เห็นได้ถ้าไม่มีกล่องข้างหน้าหรือเตี้ยกว่า
                surface += max(0, grid[i][j] - (j+1<gridSize ? grid[i][j+1] : 0));
                // หลัง: เห็นได้ถ้าไม่มีกล่องข้างหลังหรือเตี้ยกว่า
                surface += max(0, grid[i][j] - (j>0 ? grid[i][j-1] : 0));
                // ซ้าย: เห็นได้ถ้าไม่มีกล่องข้างซ้ายหรือเตี้ยกว่า
                surface += max(0, grid[i][j] - (i>0 ? grid[i-1][j] : 0));
                // ขวา: เห็นได้ถ้าไม่มีกล่องข้างขวาหรือเตี้ยกว่า
                surface += max(0, grid[i][j] - ( i+1<gridSize ? grid[i+1][j] : 0));
            }
        }
    }
    return surface;
}