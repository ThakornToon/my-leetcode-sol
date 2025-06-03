impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut currmax = 1;
        let mut currmin = 1;
        let mut res = nums[0];
        for n in nums {
            let temp = currmax * n;
            currmax = n.max(temp.max(currmin * n));
            currmin = n.min(temp.min(currmin * n));
            res = res.max(currmax);
        }
        return res;
    }
}