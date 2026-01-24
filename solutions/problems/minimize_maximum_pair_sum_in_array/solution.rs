impl Solution {
    pub fn min_pair_sum(nums: Vec<i32>) -> i32 {
        let mut sorted_nums = nums.clone();
        sorted_nums.sort();
        
        let n = sorted_nums.len();
        let mut max_sum = 0;
        
        for i in 0..n/2 {
            let pair_sum = sorted_nums[i] + sorted_nums[n - 1 - i];
            max_sum = max_sum.max(pair_sum);
        }
        
        max_sum
    }
}