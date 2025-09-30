impl Solution {
    pub fn check_possibility(nums: Vec<i32>) -> bool {
        let mut nums = nums;
        let mut modifications = 0;
        let n = nums.len();
        
        for i in 0..n-1 {
            if nums[i] > nums[i + 1] {
                modifications += 1;
                
                if modifications > 1 {
                    return false;
                }
                
                // Decide which element to modify
                if i > 0 && nums[i - 1] > nums[i + 1] {
                    // Case like [3, 4, 2] - better to raise the smaller one
                    nums[i + 1] = nums[i];
                } else {
                    // Case like [1, 4, 2] - better to lower the bigger one
                    nums[i] = nums[i + 1];
                }
            }
        }
        
        true
    }
}