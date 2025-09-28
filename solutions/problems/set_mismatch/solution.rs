impl Solution {
    pub fn find_error_nums(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        let mut result = vec![0, 0];
        
        // ใช้ marking ด้วย index
        for i in 0..nums.len() {
            let index = (nums[i].abs() - 1) as usize;
            if nums[index] < 0 {
                result[0] = nums[i].abs();  // ตัวที่ซ้ำ
            } else {
                nums[index] = -nums[index];  // mark
            }
        }
        
        // หาตัวที่หายไป
        for i in 0..nums.len() {
            if nums[i] > 0 {
                result[1] = i as i32 + 1;
                break;
            }
        }
        
        result
    }
}