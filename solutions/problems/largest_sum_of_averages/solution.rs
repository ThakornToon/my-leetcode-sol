impl Solution {
    pub fn largest_sum_of_averages(nums: Vec<i32>, k: i32) -> f64 {
        let n = nums.len();
        let k = k as usize;
        let mut prefix: Vec<f64> = vec![0.0; n + 1];
        
        // Calculate prefix sums
        for i in 0..n {
            prefix[i + 1] = prefix[i] + nums[i] as f64;
        }
        
        // DP array
        let mut dp: Vec<f64> = vec![0.0; n + 1];
        
        // Initialize: single partition
        for i in 0..n {
            dp[i + 1] = prefix[i + 1] / (i + 1) as f64;
        }
        
        // For additional partitions
        for group in 2..=k {
            let mut new_dp: Vec<f64> = vec![0.0; n + 1];
            
            for i in group..=n {
                for j in group..=i {
                    let avg = (prefix[i] - prefix[j - 1]) / (i - j + 1) as f64;
                    new_dp[i] = new_dp[i].max(dp[j - 1] + avg);
                }
            }
            
            dp = new_dp;
        }
        
        dp[n]
    }
}