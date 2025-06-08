impl Solution {
    pub fn num_islands(grid: Vec<Vec<char>>) -> i32 {
        let mut islands = 0;
        let mut grid = grid;
        for r in 0..grid.len() { 
            for c in 0..grid[0].len() { 
                if grid[r][c] == '1' { 
                    Solution::visited(&mut grid, r, c);
                    islands +=1;
                }
            }
        }
        islands
    }

    fn visited(grid: &mut Vec<Vec<char>>, r: usize, c: usize) { 
        grid[r][c] = '0';
        if r > 0 && grid[r-1][c] == '1' { 
            Solution::visited(grid, r - 1, c); 
        }
        if r < grid.len() -1 && grid[r+1][c] == '1' {             
            Solution::visited(grid, r + 1, c);
        }
        if c  > 0 && grid[r][c - 1] == '1' { 
            Solution::visited(grid, r, c - 1);
        }
        if c < grid[r].len() - 1 && grid[r][c + 1] == '1' { 
            Solution::visited(grid, r, c + 1);
        }
    }

}