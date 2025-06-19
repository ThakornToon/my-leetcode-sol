impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let total_sum: i32 = nums.iter().sum();
        if total_sum % 2 != 0 {
            return false;
        }
        
        let target = total_sum / 2;
        let mut dp = vec![false; (target + 1) as usize];
        dp[0] = true;
        
        for num in nums {
            for j in (num..=target).rev() {
                if dp[(j - num) as usize] {
                    dp[j as usize] = true;
                }
            }
            if dp[target as usize] {
                return true;
            }
        }
        
        dp[target as usize]
    }
}