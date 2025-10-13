impl Solution {
    pub fn is_ideal_permutation(nums: Vec<i32>) -> bool {
        let n = nums.len();
        if n <= 2 {
            return true;
        }
        
        let mut max_val = nums[0];
        
        for i in 2..n {
            if max_val > nums[i] {
                return false;
            }
            max_val = max_val.max(nums[i-1]);
        }
        
        true
    }
}