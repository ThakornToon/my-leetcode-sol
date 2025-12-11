impl Solution {
    pub fn check_valid_grid(grid: Vec<Vec<i32>>) -> bool {
        let n = grid.len();
        if n == 0 || grid[0][0] != 0 {
            return false;
        }
        
        // Knight moves ทั้ง 8 ทิศทาง
        let moves = [
            (-2, -1), (-2, 1), (-1, -2), (-1, 2),
            (1, -2), (1, 2), (2, -1), (2, 1),
        ];
        
        let mut current_num: i32 = 0;
        let mut x = 0;
        let mut y = 0;
        
        while (current_num as usize) < n * n - 1 {
            let mut found_next = false;
            
            for (dx, dy) in moves.iter() {
                let nx = x as i32 + dx;
                let ny = y as i32 + dy;
                
                if nx >= 0 && nx < n as i32 && ny >= 0 && ny < n as i32 {
                    let nx = nx as usize;
                    let ny = ny as usize;
                    
                    if grid[nx][ny] == current_num + 1 {
                        x = nx;
                        y = ny;
                        current_num += 1;
                        found_next = true;
                        break;
                    }
                }
            }
            
            if !found_next {
                return false;
            }
        }
        
        true
    }
}