impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let shift = (k as usize) % nums.len();
        let size = nums.len() - 1;
        for _ in 0..shift {
            let temp = nums[size];
            for i in 0..size {
                nums[size - i] = nums[size - i - 1];
            }
            nums[0] = temp;
        }
    }
}