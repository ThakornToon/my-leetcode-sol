impl Solution {
    pub fn max_sum_div_three(nums: Vec<i32>) -> i32 {
        let mut dp = vec![-1; 3];
        dp[0] = 0;  // remainder 0 สามารถมี sum = 0 ได้
        
        for num in nums {
            let mut new_dp = dp.clone();
            
            for r in 0..3 {
                if dp[r] != -1 {
                    let new_r = ((r as i32 + num) % 3) as usize;
                    let new_sum = dp[r] + num;
                    
                    if new_sum > new_dp[new_r] {
                        new_dp[new_r] = new_sum;
                    }
                }
            }
            
            dp = new_dp;
        }
        
        dp[0]
    }
}