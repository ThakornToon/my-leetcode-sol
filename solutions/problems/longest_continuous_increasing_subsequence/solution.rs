impl Solution {
    pub fn find_length_of_lcis(nums: Vec<i32>) -> i32 {
        let mut max_length = 1;
        let mut current_length = 1;
        
        for i in 1..nums.len() {
            if nums[i] > nums[i - 1] {
                current_length += 1;
                max_length = max_length.max(current_length);
            } else {
                current_length = 1;
            }
        }
        
        max_length
    }
}