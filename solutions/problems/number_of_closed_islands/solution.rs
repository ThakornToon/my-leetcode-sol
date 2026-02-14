impl Solution {
    const DIRS: [(i32, i32); 4] = [(0, 1), (1, 0), (0, -1), (-1, 0)];

    pub fn closed_island(grid: Vec<Vec<i32>>) -> i32 {
        use std::collections::VecDeque;
        
        let m = grid.len();
        let n = grid[0].len();
        let mut count = 0;
        let mut grid = grid;
        
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 0 {
                    let mut is_closed = true;
                    let mut queue = VecDeque::new();
                    queue.push_back((i as i32, j as i32));
                    grid[i][j] = 2;
                    
                    while let Some((x, y)) = queue.pop_front() {
                        // ตรวจสอบขอบ
                        if x == 0 || x as usize == m - 1 || y == 0 || y as usize == n - 1 {
                            is_closed = false;
                        }
                        
                        // สำรวจ neighbors
                        for (dx, dy) in Self::DIRS {
                            let nx = x + dx;
                            let ny = y + dy;
                            
                            if nx >= 0 && (nx as usize) < m && ny >= 0 && (ny as usize) < n 
                               && grid[nx as usize][ny as usize] == 0 {
                                grid[nx as usize][ny as usize] = 2;
                                queue.push_back((nx, ny));
                            }
                        }
                    }
                    
                    if is_closed {
                        count += 1;
                    }
                }
            }
        }
        
        count
    }
}