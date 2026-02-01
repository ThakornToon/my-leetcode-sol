impl Solution {
    pub fn minimum_cost(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut min1 = i32::MAX;
        let mut min2 = i32::MAX;
        
        for i in 1..n {
            let num = nums[i];
            if num < min1 {
                min2 = min1;
                min1 = num;
            } else if num < min2 {
                min2 = num;
            }
        }
        
        nums[0] + min1 + min2
    }
}