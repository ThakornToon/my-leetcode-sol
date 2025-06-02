bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    bool rowFlag[9][9] = {false};
    bool colFlag[9][9] = {false};
    bool cellFlag[9][9] = {false}; 
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                int c = board[i][j] - '1';
                if (rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c]) { //เช็คว่าตัวนั้นมีซ้ำไหม
                    return false;
                }
                rowFlag[i][c] = true;
                colFlag[c][j] = true;
                cellFlag[3 * (i / 3) + j / 3][c] = true;
            }
        }
    }
    return true;
}