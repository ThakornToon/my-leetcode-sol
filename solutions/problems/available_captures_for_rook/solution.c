int numRookCaptures(char** board, int boardSize, int* boardColSize) {
    // หาตำแหน่งของ rook
    int rx = -1, ry = -1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'R') {
                rx = i;
                ry = j;
                break;
            }
        }
        if (rx != -1) break;
    }
    
    int count = 0;
    
    // ทิศทาง: up, down, left, right
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int d = 0; d < 4; d++) {
        int dx = dirs[d][0];
        int dy = dirs[d][1];
        
        int x = rx + dx;
        int y = ry + dy;
        
        // เดินในทิศทางนั้นจนกว่าเจอตัวหมากหรือขอบ board
        while (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (board[x][y] == 'p') {
                count++;
                break;  // หยุดทิศทางนี้
            } else if (board[x][y] == 'B') {
                break;  // หยุดทิศทางนี้
            }
            
            x += dx;
            y += dy;
        }
    }
    
    return count;
}