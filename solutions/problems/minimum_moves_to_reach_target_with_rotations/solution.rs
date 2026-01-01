use std::collections::VecDeque;

impl Solution {
    pub fn minimum_moves(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        
        // visited[r][c][dir] : tail state dir=0 for horizontal, dir=1 for vertical
        let mut visited = vec![vec![vec![false; 2]; n]; n];
        let mut queue = VecDeque::new();
        
        // Start: tail at (0,0), horizontal
        queue.push_back((0, 0, 0)); // (r, c, dir)
        visited[0][0][0] = true;
        
        let mut steps = 0;
        
        while !queue.is_empty() {
            let size = queue.len();
            
            for _ in 0..size {
                let (r, c, dir) = queue.pop_front().unwrap();
                
                // Check if reached target
                if r == n-1 && c == n-2 && dir == 0 {
                    return steps;
                }
                
                // Move right
                if Self::can_move_right(r, c, dir, n, &grid) {
                    let (nr, nc, ndir) = (r, c + 1, dir);
                    if !visited[nr][nc][ndir] {
                        visited[nr][nc][ndir] = true;
                        queue.push_back((nr, nc, ndir));
                    }
                }
                
                // Move down
                if Self::can_move_down(r, c, dir, n, &grid) {
                    let (nr, nc, ndir) = (r + 1, c, dir);
                    if !visited[nr][nc][ndir] {
                        visited[nr][nc][ndir] = true;
                        queue.push_back((nr, nc, ndir));
                    }
                }
                
                // Rotate
                if Self::can_rotate(r, c, dir, n, &grid) {
                    let (nr, nc, ndir) = (r, c, 1 - dir); // สลับ direction
                    if !visited[nr][nc][ndir] {
                        visited[nr][nc][ndir] = true;
                        queue.push_back((nr, nc, ndir));
                    }
                }
            }
            
            steps += 1;
        }
        
        -1
    }
    
    fn can_move_right(r: usize, c: usize, dir: usize, n: usize, grid: &Vec<Vec<i32>>) -> bool {
        if dir == 0 { // horizontal: tail at (r,c), head at (r,c+1)
            c + 2 < n && grid[r][c + 2] == 0
        } else { // vertical: tail at (r,c), head at (r+1,c)
            c + 1 < n && grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0
        }
    }
    
    fn can_move_down(r: usize, c: usize, dir: usize, n: usize, grid: &Vec<Vec<i32>>) -> bool {
        if dir == 0 { // horizontal: tail at (r,c), head at (r,c+1)
            r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0
        } else { // vertical: tail at (r,c), head at (r+1,c)
            r + 2 < n && grid[r + 2][c] == 0
        }
    }
    
    fn can_rotate(r: usize, c: usize, dir: usize, n: usize, grid: &Vec<Vec<i32>>) -> bool {
        // ต้องตรวจสอบขอบเขตก่อน
        if r + 1 >= n || c + 1 >= n {
            return false;
        }
        
        if dir == 0 { 
            // หมุนตามเข็มนาฬิกา: แนวนอน → แนวตั้ง
            // งูแนวนอน: หาง (r,c), หัว (r,c+1)
            // เมื่อหมุนเป็นแนวตั้ง: หาง (r,c), หัว (r+1,c)
            // ต้องตรวจสอบว่า (r+1,c) และ (r+1,c+1) ว่าง
            grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0
        } else { 
            // หมุนทวนเข็มนาฬิกา: แนวตั้ง → แนวนอน
            // งูแนวตั้ง: หาง (r,c), หัว (r+1,c)
            // เมื่อหมุนเป็นแนวนอน: หาง (r,c), หัว (r,c+1)
            // ต้องตรวจสอบว่า (r,c+1) และ (r+1,c+1) ว่าง
            grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0
        }
    }
}