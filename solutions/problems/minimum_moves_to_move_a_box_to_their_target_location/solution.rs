use std::collections::{VecDeque, HashSet};

impl Solution {
    pub fn min_push_box(grid: Vec<Vec<char>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        
        // หาตำแหน่ง
        let (mut start_bx, mut start_by) = (0, 0);
        let (mut start_px, mut start_py) = (0, 0);
        let (mut target_x, mut target_y) = (0, 0);
        
        for i in 0..m {
            for j in 0..n {
                match grid[i][j] {
                    'B' => { start_bx = i; start_by = j; }
                    'S' => { start_px = i; start_py = j; }
                    'T' => { target_x = i; target_y = j; }
                    _ => {}
                }
            }
        }
        
        let mut visited = HashSet::new();
        let mut queue = VecDeque::new();
        
        queue.push_back((start_bx, start_by, start_px, start_py, 0));
        visited.insert((start_bx, start_by, start_px, start_py));
        
        let dx = [0, 1, 0, -1];
        let dy = [1, 0, -1, 0];
        
        while let Some((bx, by, px, py, step)) = queue.pop_front() {
            if bx == target_x && by == target_y {
                return step;
            }
            
            for d in 0..4 {
                let nbx = (bx as i32 + dx[d]) as usize;
                let nby = (by as i32 + dy[d]) as usize;
                let push_x = (bx as i32 - dx[d]) as usize;
                let push_y = (by as i32 - dy[d]) as usize;
                
                if Self::is_valid(nbx, nby, m, n, &grid) && 
                   Self::is_valid(push_x, push_y, m, n, &grid) {
                    if Self::can_player_reach(&grid, px, py, push_x, push_y, bx, by) {
                        let state = (nbx, nby, bx, by);
                        if !visited.contains(&state) {
                            visited.insert(state);
                            queue.push_back((nbx, nby, bx, by, step + 1));
                        }
                    }
                }
            }
        }
        
        -1
    }

    fn is_valid(x: usize, y: usize, m: usize, n: usize, grid: &[Vec<char>]) -> bool {
        x < m && y < n && grid[x][y] != '#'
    }
    
    fn can_player_reach(grid: &[Vec<char>], start_x: usize, start_y: usize,
                       target_x: usize, target_y: usize, box_x: usize, box_y: usize) -> bool {
        if start_x == target_x && start_y == target_y {
            return true;
        }
        
        let m = grid.len();
        let n = grid[0].len();
        
        let mut visited = vec![vec![false; n]; m];
        let mut queue = VecDeque::new();
        
        queue.push_back((start_x, start_y));
        visited[start_x][start_y] = true;
        
        let dx = [0, 1, 0, -1];
        let dy = [1, 0, -1, 0];
        
        while let Some((x, y)) = queue.pop_front() {
            for d in 0..4 {
                let nx = (x as i32 + dx[d]) as usize;
                let ny = (y as i32 + dy[d]) as usize;
                
                if Self::is_valid(nx, ny, m, n, grid) && !visited[nx][ny] && !(nx == box_x && ny == box_y) {
                    if nx == target_x && ny == target_y {
                        return true;
                    }
                    visited[nx][ny] = true;
                    queue.push_back((nx, ny));
                }
            }
        }
        
        false
    }
}