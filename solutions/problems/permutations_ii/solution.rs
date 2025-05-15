impl Solution {
    pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = Vec::new();
        let mut nums: Vec<i32> = nums;
        let mut used = vec![false; nums.len()];
        let mut current: Vec<i32> = Vec::new();
        nums.sort();

        fn backtrack(nums: &Vec<i32>, current: &mut Vec<i32>, used: &mut Vec<bool>, ans: &mut Vec<Vec<i32>>,) {
            if current.len() >= nums.len() {
                ans.push(current.clone());
                return;
            }
            for i in 0..nums.len() {
                if used[i] {
                    continue;
                }
                if i > 0 && nums[i] == nums[i - 1] && !used[i - 1] {
                    continue; //เช็คว่าไม่ซ้ำกับที่เคยวางไปในก่อนหน้านี้
                }
                used[i] = true;
                current.push(nums[i]);
                backtrack(nums, current, used, ans);
                current.pop();
                used[i] = false;
            }
        }
        backtrack(&nums, &mut current, &mut used, &mut ans);
        return ans;
    }
}