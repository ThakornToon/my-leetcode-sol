impl Solution {
    pub fn num_enclaves(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid;
        let m = grid.len();
        let n = grid[0].len();
        
        let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        let mut queue = std::collections::VecDeque::new();
        
        // Add boundary land cells to queue
        for i in 0..m {
            for j in 0..n {
                if (i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1 {
                    queue.push_back((i, j));
                    grid[i][j] = 0;
                }
            }
        }
        
        // BFS
        while let Some((x, y)) = queue.pop_front() {
            for (dx, dy) in dirs.iter() {
                let nx = x as i32 + dx;
                let ny = y as i32 + dy;
                
                if nx >= 0 && nx < m as i32 && ny >= 0 && ny < n as i32 {
                    let nx = nx as usize;
                    let ny = ny as usize;
                    
                    if grid[nx][ny] == 1 {
                        grid[nx][ny] = 0;
                        queue.push_back((nx, ny));
                    }
                }
            }
        }
        
        // Count remaining land cells
        grid.iter()
            .flat_map(|row| row.iter())
            .filter(|&&cell| cell == 1)
            .count() as i32
    }
}