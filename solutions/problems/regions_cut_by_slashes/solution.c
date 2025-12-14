// DFS สำหรับกราฟที่ใหญ่ขึ้น 3 เท่า
void dfs(int** grid, int n, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 0) {
        return;
    }
    
    grid[x][y] = 1; // ทำเครื่องหมายว่านับไปแล้ว
    
    // ไปยังเซลล์ข้างเคียง 4 ทิศ
    dfs(grid, n, x + 1, y);
    dfs(grid, n, x - 1, y);
    dfs(grid, n, x, y + 1);
    dfs(grid, n, x, y - 1);
}

int regionsBySlashes(char** grid, int gridSize) {
    int n = gridSize;
    
    // สร้าง grid ขนาด 3n × 3n
    int size = 3 * n;
    int** expanded = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        expanded[i] = (int*)calloc(size, sizeof(int));
    }
    
    // แปลงแต่ละ cell เป็น 3×3 grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int baseX = 3 * i;
            int baseY = 3 * j;
            
            if (grid[i][j] == '/') {
                // / แทนด้วยเส้นทแยงจากบนขวาไปล่างซ้าย
                expanded[baseX][baseY + 2] = 1;
                expanded[baseX + 1][baseY + 1] = 1;
                expanded[baseX + 2][baseY] = 1;
            } else if (grid[i][j] == '\\') {
                // \ แทนด้วยเส้นทแยงจากบนซ้ายไปล่างขวา
                expanded[baseX][baseY] = 1;
                expanded[baseX + 1][baseY + 1] = 1;
                expanded[baseX + 2][baseY + 2] = 1;
            }
            // ' ' (space) ไม่ได้เติมอะไร (ทั้งหมดเป็น 0)
        }
    }
    
    // นับจำนวน region โดยใช้ DFS
    int regions = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (expanded[i][j] == 0) {
                regions++;
                dfs(expanded, size, i, j);
            }
        }
    }
    
    // free memory
    for (int i = 0; i < size; i++) {
        free(expanded[i]);
    }
    free(expanded);
    
    return regions;
}