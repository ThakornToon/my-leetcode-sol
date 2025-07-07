impl Solution {
    pub fn maximum_profit(prices: Vec<i32>, k: i32) -> i64 {
        let n = prices.len();
        let k = k as usize;
        let mut dp = vec![vec![vec![i32::MIN as i64; 3]; k + 1]; n + 1];
        
        for i in 0..=k {
            dp[0][i][0] = 0;
        }

        for i in 1..=n {
            for j in (0..=k).rev() {
                let price = prices[i - 1] as i64;

                dp[i][j][0] = dp[i - 1][j][0];
                dp[i][j][0] = dp[i][j][0].max(dp[i - 1][j][1] + price); // buy
                dp[i][j][0] = dp[i][j][0].max(dp[i - 1][j][2] - price); // short sell

                dp[i][j][1] = dp[i - 1][j][1]; 
                dp[i][j][2] = dp[i - 1][j][2];
                if (j < k) { 
                    // State 1: พิจารณาจาก state 0 
                    dp[i][j][1] = dp[i - 1][j][1].max(dp[i - 1][j + 1][0] - price);
                    // State 2: พิจารณาจาก state 0 
                    dp[i][j][2] = dp[i - 1][j][2].max(dp[i - 1][j + 1][0] + price);
                } 
            }
        }
        return dp[n][0][0];
    }
}