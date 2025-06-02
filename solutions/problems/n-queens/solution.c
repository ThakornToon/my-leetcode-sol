/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
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
void backtrack(char*** res, char** board, int n, int row, int* returnSize) {
    if (row == n) {
        res[*returnSize] = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            res[*returnSize][i] = (char*)malloc((n + 1) * sizeof(char));
            strcpy(res[*returnSize][i], board[i]);
        }

        (*returnSize)++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (check(board, n, row, i)) {
            board[row][i] = 'Q';
            backtrack(res, board, n, row + 1, returnSize);
            board[row][i] = '.';
        }
    }
}
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    char*** res = (char***)malloc(500 * sizeof(char**));
    char** board = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
        board[i][n] = '\0';
    }
    backtrack(res, board, n, 0, returnSize);
    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);
    res = (char***)realloc(res, (*returnSize) * sizeof(char**));
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return res;
}