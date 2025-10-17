impl Solution {
    pub fn num_subarray_bounded_max(nums: Vec<i32>, left: i32, right: i32) -> i32 {
        let mut result = 0;
        let mut last_break = -1i32;   // ดัชนีสุดท้ายที่ > right
        let mut last_valid = -1i32;   // ดัชนีสุดท้ายที่ >= left
        
        for i in 0..nums.len() {
            let current_idx = i as i32;
            
            if nums[i] > right {
                // ตัวนี้ใหญ่เกินไป -> reset
                last_break = current_idx;
                last_valid = current_idx; // ตัวนี้เองก็ไม่ valid
            } else if nums[i] >= left {
                // ตัวนี้อยู่ในช่วงที่ต้องการ -> อัพเดท last_valid
                last_valid = current_idx;
            }
            // ถ้า nums[i] < left -> ยังใช้ last_valid เดิมได้
            
            // นับ subarrays ที่ลงท้ายที่ i
            if last_valid > last_break {
                result += last_valid - last_break;
            }
        }
        
        result
    }
}