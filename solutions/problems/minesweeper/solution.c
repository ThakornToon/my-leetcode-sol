/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void adj(char** board, int boardSize, int* boardColSize, int x, int y) {
    if (x >= boardSize || x < 0 || y >= boardColSize[0] || y < 0) {
        return;
    }
    
    if (board[x][y] == 'B' || isdigit(board[x][y])) {
        return;
    } else if (board[x][y] == 'M') {
        return;
    } else {
        int boom = 0;
        int row = boardSize;
        int col = boardColSize[0];
        
        // นับระเบิด 8 ทิศทาง
        if (x - 1 >= 0 && board[x - 1][y] == 'M') boom++;
        if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == 'M') boom++;
        if (x - 1 >= 0 && y + 1 < col && board[x - 1][y + 1] == 'M') boom++;
        if (x + 1 < row && board[x + 1][y] == 'M') boom++;
        if (x + 1 < row && y - 1 >= 0 && board[x + 1][y - 1] == 'M') boom++;
        if (x + 1 < row && y + 1 < col && board[x + 1][y + 1] == 'M') boom++;
        if (y - 1 >= 0 && board[x][y - 1] == 'M') boom++;
        if (y + 1 < col && board[x][y + 1] == 'M') boom++;

        if (boom != 0) {
            board[x][y] = '0' + boom;
            return;
        } else {
            board[x][y] = 'B';
            adj(board, boardSize, boardColSize, x - 1, y - 1);
            adj(board, boardSize, boardColSize, x - 1, y);
            adj(board, boardSize, boardColSize, x - 1, y + 1);
            adj(board, boardSize, boardColSize, x, y - 1);
            adj(board, boardSize, boardColSize, x, y + 1);
            adj(board, boardSize, boardColSize, x + 1, y - 1);
            adj(board, boardSize, boardColSize, x + 1, y);
            adj(board, boardSize, boardColSize, x + 1, y + 1);
        }
    }
}

char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = boardSize;
    *returnColumnSizes = (int*)malloc(boardSize * sizeof(int));
    for (int i = 0; i < boardSize; i++) {
        (*returnColumnSizes)[i] = boardColSize[i];
    }
    
    int x = click[0];
    int y = click[1];
    int row = boardSize;
    int col = boardColSize[0];
    
    if (board[x][y] == 'B' || isdigit(board[x][y])) {
        return board;
    } else if (board[x][y] == 'M') {
        board[x][y] = 'X';
        return board;
    } else {
        int boom = 0;
        
        // นับระเบิด 8 ทิศทาง
        if (x - 1 >= 0 && board[x - 1][y] == 'M') boom++;
        if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == 'M') boom++;
        if (x - 1 >= 0 && y + 1 < col && board[x - 1][y + 1] == 'M') boom++;
        if (x + 1 < row && board[x + 1][y] == 'M') boom++;
        if (x + 1 < row && y - 1 >= 0 && board[x + 1][y - 1] == 'M') boom++;
        if (x + 1 < row && y + 1 < col && board[x + 1][y + 1] == 'M') boom++;
        if (y - 1 >= 0 && board[x][y - 1] == 'M') boom++;
        if (y + 1 < col && board[x][y + 1] == 'M') boom++;

        if (boom != 0) {
            board[x][y] = '0' + boom;
            return board;
        } else {
            board[x][y] = 'B';
            adj(board, boardSize, boardColSize, x - 1, y - 1);
            adj(board, boardSize, boardColSize, x - 1, y);
            adj(board, boardSize, boardColSize, x - 1, y + 1);
            adj(board, boardSize, boardColSize, x, y - 1);
            adj(board, boardSize, boardColSize, x, y + 1);
            adj(board, boardSize, boardColSize, x + 1, y - 1);
            adj(board, boardSize, boardColSize, x + 1, y);
            adj(board, boardSize, boardColSize, x + 1, y + 1);
            return board;
        }
    }
}