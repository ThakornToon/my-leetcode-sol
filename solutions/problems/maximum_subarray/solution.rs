impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut max = nums[0];
        let mut curent_sum = 0;
        for n in nums {
            if curent_sum < 0 {
                curent_sum = 0;
            }
            curent_sum += n;
            max = max.max(curent_sum);
        }
        return max;
    }
}