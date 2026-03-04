impl Solution {
    const MOD: i32 = 1_000_000_007;
    pub fn paths_with_max_score(board: Vec<String>) -> Vec<i32> {
        let n = board.len();
        let board: Vec<Vec<char>> = board.into_iter()
            .map(|s| s.chars().collect())
            .collect();
        
        // dp[i][j] = (max_score, count)
        let mut dp = vec![vec![(-1, 0); n]; n];
        
        // เริ่มต้นที่จุด S
        dp[n-1][n-1] = (0, 1);
        
        // วนลูปจากล่างขึ้นบน, ขวาไปซ้าย
        for i in (0..n).rev() {
            for j in (0..n).rev() {
                // ข้ามถ้าเป็นอุปสรรค
                if board[i][j] == 'X' || dp[i][j].0 == -1 {
                    continue;
                }
                
                // คะแนนของ cell ปัจจุบัน
                let current_score = if board[i][j].is_digit(10) {
                    board[i][j].to_digit(10).unwrap() as i32
                } else {
                    0
                };
                
                // ลองเคลื่อนที่ไป 3 ทิศทาง
                let dirs = [(0, -1), (-1, 0), (-1, -1)];
                
                for &(di, dj) in &dirs {
                    let ni = i as i32 + di;
                    let nj = j as i32 + dj;
                    
                    if ni < 0 || nj < 0 { continue; }
                    
                    let ni = ni as usize;
                    let nj = nj as usize;
                    
                    let new_score = dp[i][j].0 + current_score;
                    
                    // อัปเดต dp[ni][nj]
                    if dp[ni][nj].0 < new_score {
                        dp[ni][nj] = (new_score, dp[i][j].1);
                    } else if dp[ni][nj].0 == new_score {
                        dp[ni][nj].1 = (dp[ni][nj].1 + dp[i][j].1) % Self::MOD;
                    }
                }
            }
        }
        
        // ผลลัพธ์ที่จุด E
        if dp[0][0].0 == -1 {
            vec![0, 0]
        } else {
            vec![dp[0][0].0, dp[0][0].1 % Self::MOD]
        }
    }
}