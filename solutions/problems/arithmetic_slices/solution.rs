impl Solution {
    pub fn number_of_arithmetic_slices(nums: Vec<i32>) -> i32 {
        if nums.len() < 3 {
            return 0;
        }
        
        let mut count = 0;
        let mut total = 0;
        
        for i in 2..nums.len() {
            if nums[i] - nums[i-1] == nums[i-1] - nums[i-2] {
                count += 1;
                total += count;
            } else {
                count = 0;
            }
        }
        
        total
    }
}