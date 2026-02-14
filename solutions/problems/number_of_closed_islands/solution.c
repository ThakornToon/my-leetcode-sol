int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int** grid, int m, int n, int i, int j, bool* isClosed) {
    // ถ้าเซลล์นี้คือน้ำหรือ visited แล้ว
    if (grid[i][j] != 0) {
        return;
    }
    
    // mark เป็น visited (เปลี่ยนเป็น 2)
    grid[i][j] = 2;
    
    // ตรวจสอบว่าติดขอบหรือไม่
    if (i == 0 || i == m-1 || j == 0 || j == n-1) {
        *isClosed = false;
    }
    
    // สำรวจ 4 ทิศทาง
    for (int d = 0; d < 4; d++) {
        int ni = i + dirs[d][0];
        int nj = j + dirs[d][1];
        
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 0) {
            dfs(grid, m, n, ni, nj, isClosed);
        }
    }
}

int closedIsland(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int count = 0;
    
    // สำรวจทุกเซลล์
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                bool isClosed = true;
                dfs(grid, m, n, i, j, &isClosed);
                if (isClosed) {
                    count++;
                }
            }
        }
    }
    
    return count;
}