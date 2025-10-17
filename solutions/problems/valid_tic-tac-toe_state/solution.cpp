class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int countX = 0, countO = 0;
        
        // นับจำนวน X และ O
        for (const auto& row : board) {
            for (char c : row) {
                if (c == 'X') countX++;
                else if (c == 'O') countO++;
            }
        }
        
        // ตรวจสอบจำนวน X และ O
        if (!(countX == countO || countX == countO + 1)) {
            return false;
        }
        
        // ตรวจสอบผู้ชนะ
        bool winX = false, winO = false;
        
        // ตรวจสอบแถวและคอลัมน์
        for (int i = 0; i < 3; i++) {
            // ตรวจสอบแถว
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                if (board[i][0] == 'X') winX = true;
                else winO = true;
            }
            
            // ตรวจสอบคอลัมน์
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                if (board[0][i] == 'X') winX = true;
                else winO = true;
            }
        }
        
        // ตรวจสอบแนวทแยง
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == 'X') winX = true;
            else winO = true;
        }
        
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == 'X') winX = true;
            else winO = true;
        }
        
        // ตรวจสอบเงื่อนไขการชนะ
        if (winX && winO) return false; // ทั้งสองคนชนะไม่ได้
        if (winX && countX != countO + 1) return false; // ถ้า X ชนะ ต้องมี X มากกว่า O 1 ตัว
        if (winO && countX != countO) return false; // ถ้า O ชนะ ต้องมี X เท่ากับ O
        
        return true;
    }
};