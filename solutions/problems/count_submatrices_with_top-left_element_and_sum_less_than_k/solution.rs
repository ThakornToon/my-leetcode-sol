impl Solution {
    pub fn count_submatrices(grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut count = 0;
        
        let mut prefix = vec![vec![0; n + 1]; m + 1];
        
        for i in 0..m {
            for j in 0..n {
                prefix[i + 1][j + 1] = grid[i][j] + prefix[i][j + 1] + 
                                       prefix[i + 1][j] - prefix[i][j];
            }
        }
        
        for i in 0..m {
            for j in 0..n {
                if prefix[i + 1][j + 1] <= k {
                    count += 1;
                }
            }
        }
        
        count
    }
}