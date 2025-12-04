int matrixScore(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    // ขั้นตอน 1: ทำให้บิตแรกของทุกแถวเป็น 1
    for (int i = 0; i < m; i++) {
        if (grid[i][0] == 0) {
            // Flip แถว i
            for (int j = 0; j < n; j++) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }
    
    // ขั้นตอน 2: ปรับคอลัมน์ให้มี 1 มากที่สุด
    for (int j = 1; j < n; j++) {
        int countOne = 0;
        for (int i = 0; i < m; i++) {
            countOne += grid[i][j];
        }
        
        // ถ้ามี 1 น้อยกว่าครึ่งของจำนวนแถว
        if (countOne < m - countOne) {
            // Flip คอลัมน์ j
            for (int i = 0; i < m; i++) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }
    
    // ขั้นตอน 3: คำนวณคะแนน
    int score = 0;
    for (int i = 0; i < m; i++) {
        int rowValue = 0;
        for (int j = 0; j < n; j++) {
            rowValue = (rowValue << 1) | grid[i][j];
        }
        score += rowValue;
    }
    
    return score;
}