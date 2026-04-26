impl Solution {
    pub fn contains_cycle(grid: Vec<Vec<char>>) -> bool {
        let m = grid.len();
        let n = grid[0].len();
        let mut visited = vec![vec![false; n]; m];
        let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        
        fn dfs(
            grid: &Vec<Vec<char>>, 
            i: usize, 
            j: usize, 
            pi: i32, 
            pj: i32, 
            target: char, 
            visited: &mut Vec<Vec<bool>>,
            dirs: &[(i32, i32)],
            m: usize,
            n: usize
        ) -> bool {
            visited[i][j] = true;
            
            for &(di, dj) in dirs {
                let ni = i as i32 + di;
                let nj = j as i32 + dj;
                
                if ni < 0 || ni >= m as i32 || nj < 0 || nj >= n as i32 {
                    continue;
                }
                let ni = ni as usize;
                let nj = nj as usize;
                
                if grid[ni][nj] != target { continue; }
                if ni as i32 == pi && nj as i32 == pj { continue; }
                
                if visited[ni][nj] { return true; }
                if dfs(grid, ni, nj, i as i32, j as i32, target, visited, dirs, m, n) {
                    return true;
                }
            }
            
            false
        }
        
        for i in 0..m {
            for j in 0..n {
                if !visited[i][j] {
                    if dfs(&grid, i, j, -1, -1, grid[i][j], &mut visited, &dirs, m, n) {
                        return true;
                    }
                }
            }
        }
        
        false
    }
}