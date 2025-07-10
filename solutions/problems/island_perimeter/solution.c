void next(int** grid, int gridSize, int* gridColSize, int r, int c, int* peri) {
    
    if (r < 0 || r >= gridSize || c < 0 || c >= gridColSize[0] || grid[r][c] == 0) {
        (*peri)++;
        return;
    } else if (grid[r][c] == 2) {
        return;
    }
    
    grid[r][c] = 2;
    next(grid, gridSize, gridColSize, r + 1, c, peri);
    next(grid, gridSize, gridColSize, r - 1, c, peri);
    next(grid, gridSize, gridColSize, r, c + 1, peri);
    next(grid, gridSize, gridColSize, r, c - 1, peri);
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int peri = 0;
    int i = 0;
    int j = 0;
    while (grid[i][j] == 0) {
        j++;
        if (j >= gridColSize[0]) {
            j = 0;
            i++;
        }
    }
    next(grid, gridSize, gridColSize, i, j, &peri);
    return peri;
}