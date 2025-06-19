impl Solution {
    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        let m = board.len();
        let n = board[0].len();
        
        for i in 0..m {
            for j in 0..n {
                let live_neighbours = Solution::get_live_neighbours(board, i, j, m, n);
                
                if board[i][j] == 0 {
                    // Currently dead
                    // Can become alive if has exactly three live neighbours
                    if live_neighbours == 3 {
                        board[i][j] = 2; // Newly alive
                    }
                } else if board[i][j] == 1 {
                    // <2 -> die
                    // ==2 || ==3 live
                    // >3 -> die
                    if live_neighbours < 2 || live_neighbours > 3 {
                        board[i][j] = 3; // Newly dead
                    }
                }
            }
        }
        
        // Final modifications 2->1, 3->0
        for i in 0..m {
            for j in 0..n {
                if board[i][j] == 2 {
                    board[i][j] = 1;
                } else if board[i][j] == 3 {
                    board[i][j] = 0;
                }
            }
        }
    }
    
    fn get_live_neighbours(board: &Vec<Vec<i32>>, i: usize, j: usize, m: usize, n: usize) -> i32 {
        let mut live_neighbours = 0;
        
        // Directions: up, down, left, right, and 4 diagonals
        let directions = [
            (-1, -1), (-1, 0), (-1, 1),
            (0, -1),          (0, 1),
            (1, -1),  (1, 0), (1, 1)
        ];
        
        for (di, dj) in directions.iter() {
            let ni = i as i32 + di;
            let nj = j as i32 + dj;
            
            if ni >= 0 && ni < m as i32 && nj >= 0 && nj < n as i32 {
                let ni = ni as usize;
                let nj = nj as usize;
                if board[ni][nj] == 1 || board[ni][nj] == 3 {
                    live_neighbours += 1;
                }
            }
        }
        
        live_neighbours
    }
}