impl Solution {
    pub fn min_steps(n: i32) -> i32 {
        let n = n as usize;
        let mut dp = vec![0; n + 1];
        
        for i in 2..=n {
            dp[i] = i;  // worst case: copy 1, paste i-1 times
            
            for j in 1..i {
                if i % j == 0 {
                    dp[i] = dp[i].min(dp[j] + (i / j));
                }
            }
        }
        
        dp[n] as i32
    }
}