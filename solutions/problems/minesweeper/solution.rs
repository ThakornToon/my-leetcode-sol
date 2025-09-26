impl Solution {
    pub fn update_board(board: Vec<Vec<char>>, click: Vec<i32>) -> Vec<Vec<char>> {
        let mut board = board;
        let x = click[0] as usize;
        let y = click[1] as usize;
        let rows = board.len();
        let cols = board[0].len();
        
        if board[x][y] == 'M' {
            board[x][y] = 'X';
            return board;
        }
        
        if board[x][y] != 'E' {
            return board;
        }
        
        Self::dfs(&mut board, x, y, rows, cols);
        board
    }
    
    fn dfs(board: &mut Vec<Vec<char>>, x: usize, y: usize, rows: usize, cols: usize) {
        if x >= rows || y >= cols {
            return;
        }
        
        if board[x][y] != 'E' {
            return;
        }
        
        let mut boom = 0;
        let directions = [
            (-1, -1), (-1, 0), (-1, 1),
            (0, -1),           (0, 1),
            (1, -1),  (1, 0),  (1, 1)
        ];
        
        // นับจำนวนระเบิดรอบๆ
        for (dx, dy) in directions.iter() {
            let nx = x as i32 + dx;
            let ny = y as i32 + dy;
            
            if nx >= 0 && nx < rows as i32 && ny >= 0 && ny < cols as i32 {
                let nx = nx as usize;
                let ny = ny as usize;
                if board[nx][ny] == 'M' {
                    boom += 1;
                }
            }
        }
        
        if boom > 0 {
            board[x][y] = std::char::from_digit(boom, 10).unwrap();
        } else {
            board[x][y] = 'B';
            
            // เรียก recursive ทั้ง 8 ทิศทาง
            for (dx, dy) in directions.iter() {
                let nx = x as i32 + dx;
                let ny = y as i32 + dy;
                
                if nx >= 0 && nx < rows as i32 && ny >= 0 && ny < cols as i32 {
                    Self::dfs(board, nx as usize, ny as usize, rows, cols);
                }
            }
        }
    }
}