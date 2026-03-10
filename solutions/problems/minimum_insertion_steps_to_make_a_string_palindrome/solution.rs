impl Solution {
    pub fn min_insertions(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut dp = vec![vec![0; n]; n];
        
        // base case
        for i in 0..n {
            dp[i][i] = 1;
        }
        
        // คำนวณ LPS length
        for length in 2..=n {
            for i in 0..=n - length {
                let j = i + length - 1;
                
                if s[i] == s[j] {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = dp[i + 1][j].max(dp[i][j - 1]);
                }
            }
        }
        
        (n - dp[0][n - 1]) as i32
    }
}