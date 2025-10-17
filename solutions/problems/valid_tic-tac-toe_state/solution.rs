impl Solution {
    pub fn valid_tic_tac_toe(board: Vec<String>) -> bool {
        let mut count_x = 0;
        let mut count_o = 0;
        
        // นับจำนวน X และ O
        for row in &board {
            for c in row.chars() {
                match c {
                    'X' => count_x += 1,
                    'O' => count_o += 1,
                    _ => {}
                }
            }
        }
        
        // ตรวจสอบจำนวน X และ O
        if !(count_x == count_o || count_x == count_o + 1) {
            return false;
        }
        
        // ตรวจสอบผู้ชนะ
        let mut win_x = false;
        let mut win_o = false;
        
        // แปลง board เป็น array ของ char สำหรับการเข้าถึงที่ง่ายขึ้น
        let board_chars: Vec<Vec<char>> = board.iter()
            .map(|s| s.chars().collect())
            .collect();
        
        // ตรวจสอบแถวและคอลัมน์
        for i in 0..3 {
            // ตรวจสอบแถว
            if board_chars[i][0] != ' ' && 
               board_chars[i][0] == board_chars[i][1] && 
               board_chars[i][1] == board_chars[i][2] {
                if board_chars[i][0] == 'X' {
                    win_x = true;
                } else {
                    win_o = true;
                }
            }
            
            // ตรวจสอบคอลัมน์
            if board_chars[0][i] != ' ' && 
               board_chars[0][i] == board_chars[1][i] && 
               board_chars[1][i] == board_chars[2][i] {
                if board_chars[0][i] == 'X' {
                    win_x = true;
                } else {
                    win_o = true;
                }
            }
        }
        
        // ตรวจสอบแนวทแยง
        if board_chars[0][0] != ' ' && 
           board_chars[0][0] == board_chars[1][1] && 
           board_chars[1][1] == board_chars[2][2] {
            if board_chars[0][0] == 'X' {
                win_x = true;
            } else {
                win_o = true;
            }
        }
        
        if board_chars[0][2] != ' ' && 
           board_chars[0][2] == board_chars[1][1] && 
           board_chars[1][1] == board_chars[2][0] {
            if board_chars[0][2] == 'X' {
                win_x = true;
            } else {
                win_o = true;
            }
        }
        
        // ตรวจสอบเงื่อนไขการชนะ
        if win_x && win_o {
            return false; // ทั้งสองคนชนะไม่ได้
        }
        if win_x && count_x != count_o + 1 {
            return false; // ถ้า X ชนะ ต้องมี X มากกว่า O 1 ตัว
        }
        if win_o && count_x != count_o {
            return false; // ถ้า O ชนะ ต้องมี X เท่ากับ O
        }
        
        true
    }
}