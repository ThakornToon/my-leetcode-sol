impl Solution {
    pub fn combination_sum4(nums: Vec<i32>, target: i32) -> i32 {
        let target = target as usize;
        let mut dp: Vec<usize> = vec![0; target + 1];
        dp[0] = 1;
        for i in 1..=target {
            for &num in &nums {
                let num = num as usize;
                if i >= num {
                    dp[i] = dp[i].saturating_add(dp[i - num]);
                }
            }
        }
        
        dp[target] as i32
    }
}