impl Solution {
    pub fn champagne_tower(poured: i32, query_row: i32, query_glass: i32) -> f64 {
        let mut dp = vec![vec![0.0; 101]; 101];
        dp[0][0] = poured as f64;
        
        for i in 0..=query_row as usize {
            for j in 0..=i {
                if dp[i][j] > 1.0 {
                    let overflow = dp[i][j] - 1.0;
                    dp[i][j] = 1.0;
                    dp[i+1][j] += overflow / 2.0;
                    dp[i+1][j+1] += overflow / 2.0;
                }
            }
        }
        
        dp[query_row as usize][query_glass as usize].min(1.0)
    }
}