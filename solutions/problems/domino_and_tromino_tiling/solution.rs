impl Solution {
    pub fn num_tilings(n: i32) -> i32 {
        let n = n as usize;
        const MOD: i64 = 1_000_000_007;
        
        match n {
            0 => 1,
            1 => 1,
            2 => 2,
            3 => 5,
            _ => {
                let mut dp = vec![0_i64; n + 1];
                dp[1] = 1;
                dp[2] = 2;
                dp[3] = 5;
                
                for i in 4..=n {
                    dp[i] = (2 * dp[i-1] + dp[i-3]) % MOD;
                }
                dp[n] as i32
            }
        }
    }
}