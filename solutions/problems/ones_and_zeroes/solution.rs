impl Solution {
    pub fn find_max_form(strs: Vec<String>, m: i32, n: i32) -> i32 {
        let m = m as usize;
        let n = n as usize;
        let mut dp = vec![vec![0; n + 1]; m + 1];
        
        for s in strs {
            let (zeros, ones) = s.chars().fold((0, 0), |(z, o), c| {
                if c == '0' { (z + 1, o) } else { (z, o + 1) }
            });
            let zeros = zeros as usize;
            let ones = ones as usize;
            
            for i in (zeros..=m).rev() {
                for j in (ones..=n).rev() {
                    dp[i][j] = dp[i][j].max(dp[i - zeros][j - ones] + 1);
                }
            }
        }
        
        dp[m][n]
    }
}