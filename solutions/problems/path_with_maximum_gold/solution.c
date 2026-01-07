#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dfs(int** grid, bool** visited, int row, int col, int m, int n, int currentGold, int* maxGold) {
    // ตรวจสอบขอบเขต, visited, และว่าเซลล์มีทองคำหรือไม่
    if (row < 0 || row >= m || col < 0 || col >= n || 
        visited[row][col] || grid[row][col] == 0) {
        return 0;
    }
    
    // ทำเครื่องหมายว่าเซลล์นี้ถูกเยี่ยมชมแล้ว
    visited[row][col] = true;
    currentGold += grid[row][col];
    
    // อัพเดท maxGold ทันทีที่ได้ค่ามากกว่าเดิม
    *maxGold = MAX(*maxGold, currentGold);
    
    // สำรวจ 4 ทิศทาง
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];
        
        dfs(grid, visited, newRow, newCol, m, n, currentGold, maxGold);
    }
    
    // คืนค่า visited (backtrack)
    visited[row][col] = false;
    
    return 0;
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int maxGold = 0;
    
    // สร้าง visited array
    bool** visited = (bool**)malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) {
        visited[i] = (bool*)calloc(n, sizeof(bool));
    }
    
    // พยายามเริ่มจากทุกเซลล์ที่มีทองคำ
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0) {
                dfs(grid, visited, i, j, m, n, 0, &maxGold);
            }
        }
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i < m; i++) {
        free(visited[i]);
    }
    free(visited);
    
    return maxGold;
}