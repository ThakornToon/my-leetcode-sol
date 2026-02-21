char* tictactoe(int** moves, int movesSize, int* movesColSize) {
    // สร้างกระดาน 3x3 เริ่มต้น
    char board[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    
    // วางเครื่องหมายตาม moves
    for (int i = 0; i < movesSize; i++) {
        int row = moves[i][0];
        int col = moves[i][1];
        
        // ผู้เล่น A เดินใน turn คู่ (0,2,4,...)
        if (i % 2 == 0) {
            board[row][col] = 'X';
        } else {
            board[row][col] = 'O';
        }
    }
    
    // ตรวจสอบการชนะ
    // 1. ตรวจสอบแถว
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0] == 'X' ? "A" : "B";
        }
    }
    
    // 2. ตรวจสอบคอลัมน์
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j] == 'X' ? "A" : "B";
        }
    }
    
    // 3. ตรวจสอบเส้นทแยงมุมหลัก
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0] == 'X' ? "A" : "B";
    }
    
    // 4. ตรวจสอบเส้นทแยงมุมรอง
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2] == 'X' ? "A" : "B";
    }
    
    // ตรวจสอบว่าเดินครบ 9 ตาหรือยัง
    if (movesSize == 9) {
        return "Draw";
    } else {
        return "Pending";
    }
}