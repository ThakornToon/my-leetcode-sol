impl Solution {
    pub fn find_disappeared_numbers(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        // ทำเครื่องหมายตัวเลขที่มีอยู่
        for i in 0..nums.len() {
            let index = (nums[i].abs() - 1) as usize;
            if nums[index] > 0 {
                nums[index] = -nums[index];
            }
        }
        
        let mut result = Vec::new();
        
        // หาตัวเลขที่หายไป
        for (i, &num) in nums.iter().enumerate() {
            if num > 0 {
                result.push((i + 1) as i32);
            }
        }
        
        result
    }
}