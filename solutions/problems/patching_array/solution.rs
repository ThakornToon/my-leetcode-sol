impl Solution {
    pub fn min_patches(nums: Vec<i32>, n: i32) -> i32 {
        let mut miss: i64 = 1;
        let mut i = 0;
        let mut count = 0;
        let n = n as i64;
        while (miss <= n) {
            if (i < nums.len() && nums[i] as i64 <= miss) {
                miss += nums[i] as i64;
                i += 1;
            } else {
                miss *= 2;
                count += 1;
            }
        }
        return count;
    }
}