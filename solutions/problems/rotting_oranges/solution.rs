use std::collections::VecDeque;

impl Solution {
    pub fn oranges_rotting(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid;
        let (m, n) = (grid.len(), grid[0].len());
        let mut queue = VecDeque::new();
        let mut fresh = 0;
        
        // Initialize queue and count fresh oranges
        for i in 0..m {
            for j in 0..n {
                match grid[i][j] {
                    1 => fresh += 1,
                    2 => queue.push_back((i, j)),
                    _ => {}
                }
            }
        }
        
        if fresh == 0 {
            return 0;
        }
        
        let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        let mut minutes = 0;
        
        while !queue.is_empty() && fresh > 0 {
            let size = queue.len();
            
            for _ in 0..size {
                let (x, y) = queue.pop_front().unwrap();
                
                for (dx, dy) in dirs.iter() {
                    let nx = x as i32 + dx;
                    let ny = y as i32 + dy;
                    
                    if nx >= 0 && nx < m as i32 && ny >= 0 && ny < n as i32 {
                        let nx = nx as usize;
                        let ny = ny as usize;
                        
                        if grid[nx][ny] == 1 {
                            grid[nx][ny] = 2;
                            fresh -= 1;
                            queue.push_back((nx, ny));
                        }
                    }
                }
            }
            minutes += 1;
        }
        
        if fresh == 0 { minutes } else { -1 }
    }
}