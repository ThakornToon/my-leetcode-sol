void dfs(int row, int col, char** board, int boardSize, int* boardColSize) {
    board[row][col] = 'R';
    if (row > 0 && board[row - 1][col] == 'O') {
        dfs(row - 1, col, board, boardSize, boardColSize);
    }
    if (row < boardSize - 1 && board[row + 1][col] == 'O') {
        dfs(row + 1, col, board, boardSize, boardColSize);
    }
    if (col > 0 && board[row][col - 1] == 'O') {
        dfs(row, col - 1, board, boardSize, boardColSize);
    }
    if (col < boardColSize[0] - 1 && board[row][col + 1] == 'O') {
        dfs(row, col + 1, board, boardSize, boardColSize);
    }
}

void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize < 3 || boardColSize[0] < 3) {
        return;
    }
    for (int row = 0; row < boardSize; row++) {
        if (board[row][0] == 'O') {
            dfs(row, 0, board, boardSize, boardColSize);
        }
        if (board[row][boardColSize[0] - 1] == 'O') {
            dfs(row, boardColSize[0] - 1, board, boardSize, boardColSize);
        }
    }
    for (int col = 1; col < boardColSize[0] - 1; col++) {
        if (board[0][col] == 'O') {
            dfs(0, col, board, boardSize, boardColSize);
        }
        if (board[boardSize - 1][col] == 'O') {
            dfs(boardSize - 1, col, board, boardSize, boardColSize);
        }
    }
    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardColSize[0]; ++col) {
            if (board[row][col] == 'O') {
                board[row][col] = 'X';
            } else if (board[row][col] == 'R') {
                board[row][col] = 'O';
            }
        }
    }
}