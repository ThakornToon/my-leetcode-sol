bool isMagicSquare(int** grid, int r, int c) {
    // Check center
    if (grid[r+1][c+1] != 5) return false;
    
    // Check distinct numbers 1-9
    bool seen[10] = {false};
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            int num = grid[i][j];
            if (num < 1 || num > 9 || seen[num]) return false;
            seen[num] = true;
        }
    }
    
    // Check rows
    for (int i = 0; i < 3; i++) {
        int sum = grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2];
        if (sum != 15) return false;
    }
    
    // Check columns
    for (int j = 0; j < 3; j++) {
        int sum = grid[r][c+j] + grid[r+1][c+j] + grid[r+2][c+j];
        if (sum != 15) return false;
    }
    
    // Check diagonals
    if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != 15) return false;
    if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != 15) return false;
    
    return true;
}

int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {
    if (gridSize < 3 || gridColSize[0] < 3) return 0;
    
    int count = 0;
    int n = gridColSize[0];
    
    for (int i = 0; i <= gridSize - 3; i++) {
        for (int j = 0; j <= n - 3; j++) {
            if (isMagicSquare(grid, i, j)) {
                count++;
            }
        }
    }
    
    return count;
}