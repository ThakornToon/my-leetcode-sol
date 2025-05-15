impl Solution {
    fn solve(nums: &mut Vec<i32>, index: usize, end: usize, res: &mut Vec<Vec<i32>>) {
        if index > end {
            res.push(nums.clone());
            return;
        }
        for i in index..=end {
            nums.swap(index, i);
            Self::solve(nums, index + 1, end, res);
            nums.swap(index, i);
        }
    }
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        let mut nums = nums;
        let len = nums.len();
        if len > 0 {
            Self::solve(&mut nums, 0, len - 1, &mut res);
        }
        return res;
    }
}