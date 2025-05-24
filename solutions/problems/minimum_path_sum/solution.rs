impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let (r, c) = (grid.len(), grid[0].len());
        let mut dp = vec![vec![0; c]; r];
        
        for i in 0..r {
            for j in 0..c {
                if i == 0 && j == 0 {
                    dp[i][j] = grid[i][j];
                } 
                else if j == 0 {
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                } 
                else if i == 0 {
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                } 
                else {
                    dp[i][j] = grid[i][j] + std::cmp::min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        dp[r-1][c-1]
    }
}