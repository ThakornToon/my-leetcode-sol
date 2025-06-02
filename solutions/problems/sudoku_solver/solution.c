bool check(char** board, int try, int row, int col) {
    char trynum = '0' + try;
    for (int i = 0; i < 9; i++) {
        if (trynum == board[row][i] || trynum == board[i][col]) {
            return false;
        }
    }
    int range_r = (row / 3) * 3;
    int range_c = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        if (trynum == board[range_r + i][range_c] || trynum == board[range_r + i][range_c +1] || trynum == board[range_r + i][range_c + 2]) {
            return false;
        }
    }
    return true;
}

bool backtrack(char** board, int row, int col) {
    while (row < 9 && board[row][col] != '.') {
        col++;
        if (col > 8) {
            col = 0;
            row++;
        }
    }
    if (row == 9) {
        return true;
    }
    for (int i = 1; i <= 9; i++) {
        if (check(board, i, row, col)) {
            board[row][col] = '0' + i;
            bool end = backtrack(board, row, col);
            if (end) {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    backtrack(board, 0, 0);
}