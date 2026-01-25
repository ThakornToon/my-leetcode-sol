impl Solution {
    pub fn minimum_difference(nums: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;
        let n = nums.len();
        
        // กรณีพิเศษ
        if k == 1 || n <= 1 {
            return 0;
        }
        
        let mut sorted_nums = nums.clone();
        sorted_nums.sort();
        
        let mut min_diff = i32::MAX;
        
        // ใช้ sliding window
        for i in 0..=(n - k) {
            let diff = sorted_nums[i + k - 1] - sorted_nums[i];
            min_diff = min_diff.min(diff);
        }
        
        min_diff
    }
}