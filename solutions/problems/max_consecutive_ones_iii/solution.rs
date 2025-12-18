impl Solution {
    pub fn longest_ones(nums: Vec<i32>, k: i32) -> i32 {
        let k = k as i32;
        let mut left = 0;
        let mut zeros = 0;
        let mut max_len = 0;
        
        for right in 0..nums.len() {
            if nums[right] == 0 {
                zeros += 1;
            }
            
            // ไม่ต้องใช้ while ซ้อน, ใช้ if แทน
            if zeros > k {
                if nums[left] == 0 {
                    zeros -= 1;
                }
                left += 1;
            }
            
            max_len = max_len.max((right - left + 1) as i32);
        }
        
        max_len
    }
}