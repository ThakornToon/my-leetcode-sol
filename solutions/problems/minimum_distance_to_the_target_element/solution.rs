impl Solution {
    pub fn get_min_distance(nums: Vec<i32>, target: i32, start: i32) -> i32 {
        let n = nums.len();
        let start = start as usize;
        
        for d in 0..n {
            // ตรวจสอบทางซ้าย
            if start >= d && nums[start - d] == target {
                return d as i32;
            }
            // ตรวจสอบทางขวา
            if start + d < n && nums[start + d] == target {
                return d as i32;
            }
        }
        
        -1
    }
}