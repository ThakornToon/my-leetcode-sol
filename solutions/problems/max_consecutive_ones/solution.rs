impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let mut count = 0;
        for n in nums {
            if (n == 1) {
                count += 1;
            } else {
                res = res.max(count);
                count = 0;
            }
        }
        return res.max(count);
    }
}