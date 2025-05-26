bool dfs (char** board, int boardSize, int boardColSize, char* word, int i, int j, int n) { 
    if (n == strlen(word)) {
        return true;
    }
    if(i < 0 || i >= boardSize || j < 0 || j >= boardColSize || board[i][j] != word[n]) {
        return false;
    }
    board[i][j] = '0';
    bool neighbor = dfs(board, boardSize, boardColSize, word, i+1, j, n+1) || dfs(board, boardSize, boardColSize, word, i-1, j, n+1) || dfs(board, boardSize, boardColSize, word, i, j-1, n+1) || dfs(board, boardSize, boardColSize, word, i, j+1, n+1);
    board[i][j] = word[n];
    return neighbor;
}


bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int word_len = strlen(word);
    if (word_len > boardSize * boardColSize[0]) {
        return false;
    }
    int c_frist = 0;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            if (board[i][j] == word[0]) {
                c_frist++;
            }
            else if (board[i][j] == word[word_len-1]) {
                c_frist--;
            }
        }
    }
    if (c_frist > 0) {
        int l = 0;
        int r = word_len - 1;
        while (l < r) {
            char temp = word[l];
            word[l] = word[r];
            word[r] = temp;
            r--;
            l++;
        }
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            if (dfs(board, boardSize, boardColSize[0], word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}