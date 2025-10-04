#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dfs(int** grid, int gridSize, int* gridColSize, int i, int j) {
    // Check boundaries and if it's land
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize[i] || grid[i][j] == 0) {
        return 0;
    }
    
    // Mark as visited by setting to 0
    grid[i][j] = 0;
    
    // Explore all 4 directions and accumulate area
    int area = 1;
    area += dfs(grid, gridSize, gridColSize, i + 1, j); // down
    area += dfs(grid, gridSize, gridColSize, i - 1, j); // up
    area += dfs(grid, gridSize, gridColSize, i, j + 1); // right
    area += dfs(grid, gridSize, gridColSize, i, j - 1); // left
    
    return area;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int maxArea = 0;
    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                int area = dfs(grid, gridSize, gridColSize, i, j);
                maxArea = MAX(maxArea, area);
            }
        }
    }
    
    return maxArea;
}