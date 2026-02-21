impl Solution {
    pub fn tictactoe(moves: Vec<Vec<i32>>) -> String {
        // สร้างกระดาน
        let mut board = vec![vec![' '; 3]; 3];
        
        // วางเครื่องหมาย
        for (i, mov) in moves.iter().enumerate() {
            let row = mov[0] as usize;
            let col = mov[1] as usize;
            board[row][col] = if i % 2 == 0 { 'X' } else { 'O' };
        }
        
        // ตรวจสอบแถว
        for i in 0..3 {
            if board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] {
                return (if board[i][0] == 'X' { "A" } else { "B" }).to_string();
            }
        }
        
        // ตรวจสอบคอลัมน์
        for j in 0..3 {
            if board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j] {
                return (if board[0][j] == 'X' { "A" } else { "B" }).to_string();
            }
        }
        
        // ตรวจสอบเส้นทแยงมุมหลัก
        if board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] {
            return (if board[0][0] == 'X' { "A" } else { "B" }).to_string();
        }
        
        // ตรวจสอบเส้นทแยงมุมรอง
        if board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0] {
            return (if board[0][2] == 'X' { "A" } else { "B" }).to_string();
        }
        
        // ตรวจสอบจำนวนการเดิน
        if moves.len() == 9 {
            "Draw".to_string()
        } else {
            "Pending".to_string()
        }
    }
}