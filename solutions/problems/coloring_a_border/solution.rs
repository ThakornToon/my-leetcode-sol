impl Solution {
    pub fn color_border(grid: Vec<Vec<i32>>, row: i32, col: i32, color: i32) -> Vec<Vec<i32>> {
        let m = grid.len();
        let n = grid[0].len();
        let row = row as usize;
        let col = col as usize;
        let original_color = grid[row][col];
        
        if original_color == color {
            return grid;
        }
        
        let mut visited = vec![vec![false; n]; m];
        let mut is_border = vec![vec![false; n]; m];
        
        let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        
        fn dfs(
            r: usize, c: usize,
            m: usize, n: usize,
            grid: &Vec<Vec<i32>>,
            original_color: i32,
            visited: &mut Vec<Vec<bool>>,
            is_border: &mut Vec<Vec<bool>>,
            dirs: &[(i32, i32)]
        ) {
            visited[r][c] = true;
            
            // Check if on boundary
            if r == 0 || r == m-1 || c == 0 || c == n-1 {
                is_border[r][c] = true;
            }
            
            for (dr, dc) in dirs {
                let nr = r as i32 + dr;
                let nc = c as i32 + dc;
                
                if nr >= 0 && nr < m as i32 && nc >= 0 && nc < n as i32 {
                    let nr = nr as usize;
                    let nc = nc as usize;
                    
                    if !visited[nr][nc] {
                        if grid[nr][nc] == original_color {
                            dfs(nr, nc, m, n, grid, original_color, visited, is_border, dirs);
                        } else {
                            // Different color neighbor
                            is_border[r][c] = true;
                        }
                    }
                } else {
                    // Out of bounds
                    is_border[r][c] = true;
                }
            }
        }
        
        dfs(row, col, m, n, &grid, original_color, &mut visited, &mut is_border, &dirs);
        
        let mut result = grid;
        for i in 0..m {
            for j in 0..n {
                if is_border[i][j] {
                    result[i][j] = color;
                }
            }
        }
        
        result
    }
}