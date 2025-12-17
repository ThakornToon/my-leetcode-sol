int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(int** grid, int m, int n, int x, int y, int emptyCount) {
    // ตรวจสอบขอบเขตและอุปสรรค
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1) {
        return 0;
    }
    
    // ถ้าเจอจุดสิ้นสุด
    if (grid[x][y] == 2) {
        // ตรวจสอบว่าเดินผ่านทุกช่องแล้วหรือไม่
        return emptyCount == 0 ? 1 : 0;
    }
    
    // Mark เป็น visited (เปลี่ยนเป็น -1)
    grid[x][y] = -1;
    int paths = 0;
    
    // สำรวจทั้ง 4 ทิศทาง
    for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];
        paths += dfs(grid, m, n, nx, ny, emptyCount - 1);
    }
    
    // Backtrack: กลับค่าเดิม
    grid[x][y] = 0;
    
    return paths;
}

int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    int startX = 0, startY = 0;
    int emptyCount = 1; // รวมจุดเริ่มต้นด้วย
    
    // หาจุดเริ่มต้นและนับช่องที่ต้องเดินผ่าน
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                startX = i;
                startY = j;
            } else if (grid[i][j] == 0) {
                emptyCount++;
            }
        }
    }
    
    return dfs(grid, m, n, startX, startY, emptyCount);
}