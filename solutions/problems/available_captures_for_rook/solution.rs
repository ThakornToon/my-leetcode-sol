impl Solution {
    pub fn num_rook_captures(board: Vec<Vec<char>>) -> i32 {
        // Find rook position
        let mut rx = 0;
        let mut ry = 0;
        
        for i in 0..8 {
            for j in 0..8 {
                if board[i][j] == 'R' {
                    rx = i;
                    ry = j;
                    break;
                }
            }
        }
        
        let mut captures = 0;
        let directions = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        
        for (dx, dy) in directions.iter() {
            let mut x = rx as i32 + dx;
            let mut y = ry as i32 + dy;
            
            while x >= 0 && x < 8 && y >= 0 && y < 8 {
                let xi = x as usize;
                let yi = y as usize;
                
                match board[xi][yi] {
                    'B' => break,
                    'p' => {
                        captures += 1;
                        break;
                    }
                    _ => {
                        x += dx;
                        y += dy;
                    }
                }
            }
        }
        
        captures
    }
}