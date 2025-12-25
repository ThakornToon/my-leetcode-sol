impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        let n = n as usize;
        if n == 0 {
            return 0;
        }
        if n == 1 || n == 2 {
            return 1;
        }
        
        let mut dp = vec![0; n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for i in 3..=n {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        
        dp[n]
    }
}