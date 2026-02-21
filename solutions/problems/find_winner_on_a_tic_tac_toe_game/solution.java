class Solution {
    public String tictactoe(int[][] moves) {
        // สร้างกระดาน
        char[][] board = new char[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        
        // วางเครื่องหมาย
        for (int i = 0; i < moves.length; i++) {
            int row = moves[i][0];
            int col = moves[i][1];
            board[row][col] = (i % 2 == 0) ? 'X' : 'O';
        }
        
        // ตรวจสอบแถว
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' && 
                board[i][0] == board[i][1] && 
                board[i][1] == board[i][2]) {
                return (board[i][0] == 'X') ? "A" : "B";
            }
        }
        
        // ตรวจสอบคอลัมน์
        for (int j = 0; j < 3; j++) {
            if (board[0][j] != ' ' && 
                board[0][j] == board[1][j] && 
                board[1][j] == board[2][j]) {
                return (board[0][j] == 'X') ? "A" : "B";
            }
        }
        
        // ตรวจสอบเส้นทแยงมุมหลัก
        if (board[0][0] != ' ' && 
            board[0][0] == board[1][1] && 
            board[1][1] == board[2][2]) {
            return (board[0][0] == 'X') ? "A" : "B";
        }
        
        // ตรวจสอบเส้นทแยงมุมรอง
        if (board[0][2] != ' ' && 
            board[0][2] == board[1][1] && 
            board[1][1] == board[2][0]) {
            return (board[0][2] == 'X') ? "A" : "B";
        }
        
        // ตรวจสอบจำนวนการเดิน
        if (moves.length == 9) {
            return "Draw";
        } else {
            return "Pending";
        }
    }
}