use std::collections::HashSet;
use std::collections::VecDeque;

impl Solution {
    pub fn shortest_path(grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let k = k as usize;
        
        if m == 1 && n == 1 {
            return 0;
        }
        
        let mut queue = VecDeque::new();
        let mut visited = HashSet::new();
        
        queue.push_back((0, 0, k, 0));
        visited.insert((0, 0, k));
        
        let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        
        while let Some((row, col, remaining_k, dist)) = queue.pop_front() {
            for &(dr, dc) in &dirs {
                let nr = row as i32 + dr;
                let nc = col as i32 + dc;
                
                if nr < 0 || nr >= m as i32 || nc < 0 || nc >= n as i32 {
                    continue;
                }
                
                let nr = nr as usize;
                let nc = nc as usize;
                let mut new_k = remaining_k;
                
                if grid[nr][nc] == 1 {
                    if new_k == 0 {
                        continue;
                    }
                    new_k -= 1;
                }
                
                if !visited.contains(&(nr, nc, new_k)) {
                    if nr == m - 1 && nc == n - 1 {
                        return dist + 1;
                    }
                    
                    visited.insert((nr, nc, new_k));
                    queue.push_back((nr, nc, new_k, dist + 1));
                }
            }
        }
        
        -1

    }
}