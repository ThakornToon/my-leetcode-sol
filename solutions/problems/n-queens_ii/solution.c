bool check(char** board, int n, int row, int col) {
    for (int i = 1; i <= row; i++) {
        if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') {
            return false;
        }
        if (row - i >= 0 && col + i < n && board[row - i][col + i] == 'Q') {
            return false;
        }
        if (row - i >= 0 && board[row - i][col] == 'Q') {
            return false;
        }
    }
    return true;
}
void backtrack(char** board, int n, int row, int* count) {
    if (row == n) {
        (*count)++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (check(board, n, row, i)) {
            board[row][i] = 'Q';
            backtrack(board, n, row + 1, count);
            board[row][i] = '.';
        }
    }
}
int totalNQueens(int n) {
    int count = 0;
    char** board = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
        board[i][n] = '\0';
    }
    backtrack(board, n, 0, &count);
    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);
    
    return count; 
}