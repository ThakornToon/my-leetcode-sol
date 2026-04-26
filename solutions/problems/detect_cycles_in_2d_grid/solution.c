int m, n;
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool dfs(char** grid, int i, int j, int pi, int pj, char target, bool** visited) {
    visited[i][j] = true;
    
    for (int d = 0; d < 4; d++) {
        int ni = i + dirs[d][0];
        int nj = j + dirs[d][1];
        
        // ตรวจสอบขอบเขต
        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
        
        // ตรวจสอบตัวอักษรเดียวกัน
        if (grid[ni][nj] != target) continue;
        
        // ถ้าเป็น parent ให้ข้าม
        if (ni == pi && nj == pj) continue;
        
        if (visited[ni][nj]) {
            return true;  // เจอ cycle
        }
        
        if (dfs(grid, ni, nj, i, j, target, visited)) {
            return true;
        }
    }
    
    return false;
}

bool containsCycle(char** grid, int gridSize, int* gridColSize) {
    m = gridSize;
    n = gridColSize[0];
    
    // สร้าง visited array
    bool** visited = (bool**)malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) {
        visited[i] = (bool*)calloc(n, sizeof(bool));
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                if (dfs(grid, i, j, -1, -1, grid[i][j], visited)) {
                    // คืนหน่วยความจำ
                    for (int x = 0; x < m; x++) free(visited[x]);
                    free(visited);
                    return true;
                }
            }
        }
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i < m; i++) free(visited[i]);
    free(visited);
    
    return false;
}