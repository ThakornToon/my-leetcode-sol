impl Solution {
    pub fn num_rolls_to_target(n: i32, k: i32, target: i32) -> i32 {
        const MOD: i32 = 1_000_000_007;
        let (n, k, target) = (n as usize, k as usize, target as usize);
        
        let mut dp = vec![0; target + 1];
        dp[0] = 1;
        
        for _ in 0..n {
            let mut new_dp = vec![0; target + 1];
            
            for sum in 0..=target {
                if dp[sum] == 0 {
                    continue;
                }
                
                for face in 1..=k {
                    if sum + face <= target {
                        new_dp[sum + face] = (new_dp[sum + face] + dp[sum]) % MOD;
                    }
                }
            }
            
            dp = new_dp;
        }
        
        dp[target]
    }
}