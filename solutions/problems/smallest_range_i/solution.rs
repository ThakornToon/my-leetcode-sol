impl Solution {
    pub fn smallest_range_i(nums: Vec<i32>, k: i32) -> i32 {
        let min_val = nums.iter().min().unwrap();
        let max_val = nums.iter().max().unwrap();
        
        let result = (max_val - k) - (min_val + k);
        if result > 0 { result } else { 0 }
    }
}