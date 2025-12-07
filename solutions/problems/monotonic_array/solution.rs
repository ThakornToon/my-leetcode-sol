impl Solution {
    pub fn is_monotonic(nums: Vec<i32>) -> bool {
        let mut inc = true;
        let mut dec = true;
        
        for i in 0..nums.len() - 1 {
            if nums[i] < nums[i+1] {
                dec = false;
            }
            if nums[i] > nums[i+1] {
                inc = false;
            }
            
            if !inc && !dec {
                return false;
            }
        }
        
        inc || dec
    }
}