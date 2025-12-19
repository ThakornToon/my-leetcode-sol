int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int** grid, int m, int n, int i, int j) {
    // ตรวจสอบขอบเขตและว่าเป็น land (1) หรือไม่
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
        return;
    }
    
    // Mark เป็น visited (เปลี่ยนเป็น 0)
    grid[i][j] = 0;
    
    // DFS ไป 4 ทิศทาง
    for (int d = 0; d < 4; d++) {
        int ni = i + dirs[d][0];
        int nj = j + dirs[d][1];
        dfs(grid, m, n, ni, nj);
    }
}

int numEnclaves(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    // 1. สำรวจขอบด้านซ้ายและขวา
    for (int i = 0; i < m; i++) {
        // ซ้ายสุด
        if (grid[i][0] == 1) {
            dfs(grid, m, n, i, 0);
        }
        // ขวาสุด
        if (grid[i][n-1] == 1) {
            dfs(grid, m, n, i, n-1);
        }
    }
    
    // 2. สำรวจขอบด้านบนและล่าง
    for (int j = 0; j < n; j++) {
        // บนสุด
        if (grid[0][j] == 1) {
            dfs(grid, m, n, 0, j);
        }
        // ล่างสุด
        if (grid[m-1][j] == 1) {
            dfs(grid, m, n, m-1, j);
        }
    }
    
    // 3. นับ land cells ที่เหลือ (enclaves)
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }
    
    return count;
}