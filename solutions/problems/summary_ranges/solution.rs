impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let mut ans = Vec::new();
        let mut i = 0;
        while i < nums.len() {
            let start = nums[i];
            while i < nums.len() - 1 && nums[i + 1] == nums[i] + 1 {
                i += 1;
            }
            let mut s = start.to_string();
            if start != nums[i] {
                s += "->";
                s += &nums[i].to_string();
            }
            ans.push(s);
            i += 1;
        }
        ans
    }
}