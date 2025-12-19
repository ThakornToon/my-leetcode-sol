impl Solution {
    pub fn longest_arith_seq_length(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n <= 2 {
            return n as i32;
        }
        
        const OFFSET: usize = 500;
        const RANGE: usize = 1001; // 0 to 1000
        
        // dp[i][diff] = length of sequence ending at i with difference (diff - OFFSET)
        let mut dp = vec![vec![1; RANGE]; n];
        
        let mut max_len = 2;
        
        for i in 1..n {
            for j in 0..i {
                let diff = (nums[i] - nums[j] + OFFSET as i32) as usize;
                
                dp[i][diff] = dp[j][diff] + 1;
                max_len = max_len.max(dp[i][diff]);
            }
        }
        
        max_len
    }
}