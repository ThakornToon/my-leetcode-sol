impl Solution {
    pub fn first_missing_positive(nums: Vec<i32>) -> i32 {
        let mut nums = nums;

        //nums.sort(); O(nlogn)
        let mut i = 0;
        while i < nums.len() {
            let correct_pos = nums[i] - 1;
            if nums[i] > 0 && nums[i] <= nums.len() as i32 && nums[i] != nums[correct_pos as usize] {
                nums.swap(i, correct_pos as usize);
            } else {
                i += 1;
            }
        }

        for i in 0..nums.len() {
            if nums[i] != (i + 1) as i32 {
                return (i + 1) as i32;
            }
        }
        return (nums.len()+1) as i32;
    }
}