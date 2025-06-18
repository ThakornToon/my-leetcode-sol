impl Solution {
    pub fn wiggle_max_length(nums: Vec<i32>) -> i32 {
        if nums.len() < 2 {
            return nums.len() as i32;
        }
        
        let mut prev_diff = nums[1] - nums[0];
        let mut count = if prev_diff != 0 { 2 } else { 1 };
        
        for i in 2..nums.len() {
            let diff = nums[i] - nums[i-1];
            if (diff > 0 && prev_diff <= 0) || (diff < 0 && prev_diff >= 0) {
                count += 1;
                prev_diff = diff;
            }
        }
        
        count
    }
}