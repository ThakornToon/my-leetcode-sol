impl Solution {
    pub fn increasing_triplet(nums: Vec<i32>) -> bool {
        let mut min1 = i32::MAX;
        let mut min2 = i32::MAX;
        for i in 0..nums.len() {
            if (nums[i] <= min1) {
                min1 = nums[i];  
            } else if (nums[i] <= min2) {
                min2 = nums[i];  
            } else {
                return true;  
            }
        }
        return false;
    }
}