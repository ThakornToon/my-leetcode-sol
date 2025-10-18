int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    
    // สร้าง arrays สำหรับเก็บค่า max ของแต่ละแถวและคอลัมน์
    int* rowMax = (int*)calloc(n, sizeof(int));
    int* colMax = (int*)calloc(n, sizeof(int));
    
    // หาค่า max ของแต่ละแถวและคอลัมน์
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > rowMax[i]) {
                rowMax[i] = grid[i][j];
            }
            if (grid[i][j] > colMax[j]) {
                colMax[j] = grid[i][j];
            }
        }
    }
    
    // คำนวณผลรวมความสูงที่เพิ่มได้
    int totalIncrease = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // ความสูงใหม่ต้องไม่เกิน min ของ max ในแถวและคอลัมน์
            int newHeight = (rowMax[i] < colMax[j]) ? rowMax[i] : colMax[j];
            totalIncrease += newHeight - grid[i][j];
        }
    }
    
    free(rowMax);
    free(colMax);
    
    return totalIncrease;
}