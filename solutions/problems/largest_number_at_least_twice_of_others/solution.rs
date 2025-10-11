impl Solution {
    pub fn dominant_index(nums: Vec<i32>) -> i32 {
        let mut max_index = 0;
        let mut max_val = nums[0];
        let mut second_max = -1;
        
        for (i, &num) in nums.iter().enumerate().skip(1) {
            if num > max_val {
                second_max = max_val;
                max_val = num;
                max_index = i;
            } else if num > second_max {
                second_max = num;
            }
        }
        
        if max_val >= 2 * second_max {
            max_index as i32
        } else {
            -1
        }
    }
}