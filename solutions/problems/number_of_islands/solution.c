void visit(char** grid, int r,  int c, int row, int col){

    if(r >= row || r < 0 || c >= col || c < 0 || grid[r][c] == '0') return;

    grid[r][c] = '0'; // 1 -> 0

    visit(grid, r+1, c, row, col);
    visit(grid, r-1, c, row, col);
    visit(grid, r, c+1, row, col);
    visit(grid, r, c-1, row, col);

}



int numIslands(char** grid, int gridSize, int* gridColSize) {

    int row = gridSize;
    int col = gridColSize[0];
    int ans = 0;

    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            if(grid[r][c] == '1'){
                visit(grid, r, c, row, col);
                ans += 1;
            }
        }
    }

    return ans;
}