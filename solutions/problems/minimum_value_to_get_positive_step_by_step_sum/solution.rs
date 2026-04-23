impl Solution {
    pub fn min_start_value(nums: Vec<i32>) -> i32 {
        let mut prefix_sum = 0;
        let mut min_prefix = 0;
        
        for &num in &nums {
            prefix_sum += num;
            min_prefix = min_prefix.min(prefix_sum);
        }
        
        1 - min_prefix
    }
}