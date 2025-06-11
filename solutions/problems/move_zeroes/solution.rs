impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let mut nonZero = 0;
        for i in 0..nums.len() {
            if (nums[i] != 0) {
                let temp = nums[i];
                nums[i] = nums[nonZero];
                nums[nonZero] = temp;
                nonZero+=1;
            }
        }
    }
}