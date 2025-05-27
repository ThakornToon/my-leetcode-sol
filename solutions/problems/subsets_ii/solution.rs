impl Solution {
    pub fn subsets_with_dup(nums: Vec<i32>) -> Vec<Vec<i32>> {
        fn backtrack(index: usize, sub: &mut Vec<i32>, nums: &Vec<i32>, res: &mut Vec<Vec<i32>>) {
            res.push(sub.clone());

            for i in index..nums.len() {
                if i > index && nums[i] == nums[i-1] {
                    continue;
                }
                sub.push(nums[i]);
                backtrack(i + 1, sub, nums, res);
                sub.pop();
            }
        }
        let mut nums = nums;
        nums.sort();
        let mut res: Vec<Vec<i32>> = Vec::new();
        let mut sub: Vec<i32> = Vec::new();
        backtrack(0, &mut sub, &nums, &mut res);
        res
    }
}