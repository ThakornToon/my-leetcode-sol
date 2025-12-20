/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** colorBorder(int** grid, int gridSize, int* gridColSize, int row, int col, int color, int* returnSize, int** returnColumnSizes) {
    int m = gridSize, n = gridColSize[0];
    int originalColor = grid[row][col];
    
    if (originalColor == color) {
        // Return copy
        *returnSize = m;
        *returnColumnSizes = (int*)malloc(m * sizeof(int));
        int** result = (int**)malloc(m * sizeof(int*));
        for (int i = 0; i < m; i++) {
            (*returnColumnSizes)[i] = n;
            result[i] = (int*)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) result[i][j] = grid[i][j];
        }
        return result;
    }
    
    // visited array
    bool** visited = (bool**)malloc(m * sizeof(bool*));
    // border array
    bool** isBorder = (bool**)malloc(m * sizeof(bool*));
    
    for (int i = 0; i < m; i++) {
        visited[i] = (bool*)calloc(n, sizeof(bool));
        isBorder[i] = (bool*)calloc(n, sizeof(bool));
    }
    
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    // DFS ที่ตรวจสอบ border ไปด้วย
    void dfs(int r, int c) {
        visited[r][c] = true;
        
        // ตรวจสอบ 4 ทิศทางทันที
        for (int d = 0; d < 4; d++) {
            int nr = r + dirs[d][0];
            int nc = c + dirs[d][1];
            
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                // อยู่ขอบ grid
                isBorder[r][c] = true;
            } else if (grid[nr][nc] != originalColor) {
                // เพื่อนบ้านสีต่าง
                isBorder[r][c] = true;
            } else if (!visited[nr][nc]) {
                // เพื่อนบ้านสีเดียวกันและยังไม่ visited
                dfs(nr, nc);
            }
        }
    }
    
    dfs(row, col);
    
    // สร้างผลลัพธ์
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    int** result = (int**)malloc(m * sizeof(int*));
    
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
        result[i] = (int*)malloc(n * sizeof(int));
        
        for (int j = 0; j < n; j++) {
            if (isBorder[i][j]) {
                result[i][j] = color;
            } else {
                result[i][j] = grid[i][j];
            }
        }
        
        free(visited[i]);
        free(isBorder[i]);
    }
    
    free(visited);
    free(isBorder);
    
    return result;
}