impl Solution {
    pub fn find_number_of_lis(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut dp = vec![1; n];     // length of LIS ending at i
        let mut count = vec![1; n];  // number of LIS ending at i
        let mut max_len = 1;
        let mut result = 0;
        
        for i in 0..n {
            for j in 0..i {
                if nums[i] > nums[j] {
                    if dp[j] + 1 > dp[i] {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if dp[j] + 1 == dp[i] {
                        count[i] += count[j];
                    }
                }
            }
            
            if dp[i] > max_len {
                max_len = dp[i];
                result = count[i];
            } else if dp[i] == max_len {
                result += count[i];
            }
        }
        
        result
    }
}