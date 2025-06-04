use std::collections::HashSet;

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let k = k as usize;
        let mut seen = HashSet::with_capacity(k + 1);

        for (i, &num) in nums.iter().enumerate() {
            if !seen.insert(num) {
                return true;
            }
            if i + 1 > k {
                seen.remove(&nums[i - k]);
            } 
        }
        false
    }
}