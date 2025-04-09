impl Solution {
    pub fn remove_duplicates(nums:&mut Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0;
        }

        let mut j = 0;
        for i in 1..nums.len() {
            if nums[j] != nums[i] {
                j += 1;
                nums[j] = nums[i];
            }
        }

        (j + 1) as i32
    }
}