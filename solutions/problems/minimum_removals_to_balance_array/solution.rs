impl Solution {
    pub fn min_removal(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut sorted_nums = nums.clone();
        sorted_nums.sort();
        
        let k = k as i64;
        let mut left = 0;
        let mut max_length = 1;  // อย่างน้อย 1 ตัว
        
        for right in 0..n {
            // ขยาย right ตราบใดที่ตรงเงื่อนไข
            while left <= right && 
                  (sorted_nums[right] as i64) > k * (sorted_nums[left] as i64) {
                left += 1;
            }
            
            // อัปเดตความยาวช่วงที่ยาวที่สุด
            let current_length = right - left + 1;
            max_length = max_length.max(current_length);
        }
        
        (n - max_length) as i32
    }
}