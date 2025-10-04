impl Solution {
    pub fn max_area_of_island(mut grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut max_area = 0;
        
        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 1 {
                    let area = Self::dfs(&mut grid, i, j);
                    max_area = max_area.max(area);
                }
            }
        }
        
        max_area
    }
    
    fn dfs(grid: &mut Vec<Vec<i32>>, i: usize, j: usize) -> i32 {
        if i >= grid.len() || j >= grid[0].len() || grid[i][j] == 0 {
            return 0;
        }
        
        grid[i][j] = 0; // Mark as visited
        
        let mut area = 1;
        
        // Check all four directions
        if i > 0 {
            area += Self::dfs(grid, i - 1, j); // up
        }
        if i < grid.len() - 1 {
            area += Self::dfs(grid, i + 1, j); // down
        }
        if j > 0 {
            area += Self::dfs(grid, i, j - 1); // left
        }
        if j < grid[0].len() - 1 {
            area += Self::dfs(grid, i, j + 1); // right
        }
        
        area
    }
}