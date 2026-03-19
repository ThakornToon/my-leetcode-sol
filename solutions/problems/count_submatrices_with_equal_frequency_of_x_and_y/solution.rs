impl Solution {
    pub fn number_of_submatrices(grid: Vec<Vec<char>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut count = 0;
        
        // prefix sums
        let mut prefix_x = vec![vec![0; n + 1]; m + 1];
        let mut prefix_y = vec![vec![0; n + 1]; m + 1];
        
        for i in 0..m {
            for j in 0..n {
                let val_x = if grid[i][j] == 'X' { 1 } else { 0 };
                let val_y = if grid[i][j] == 'Y' { 1 } else { 0 };
                
                prefix_x[i + 1][j + 1] = val_x + prefix_x[i][j + 1] + 
                                         prefix_x[i + 1][j] - prefix_x[i][j];
                prefix_y[i + 1][j + 1] = val_y + prefix_y[i][j + 1] + 
                                         prefix_y[i + 1][j] - prefix_y[i][j];
            }
        }
        
        for i in 0..m {
            for j in 0..n {
                if prefix_x[i + 1][j + 1] > 0 && 
                   prefix_x[i + 1][j + 1] == prefix_y[i + 1][j + 1] {
                    count += 1;
                }
            }
        }
        
        count
    }
}