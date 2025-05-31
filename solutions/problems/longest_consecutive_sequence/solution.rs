use std::collections::HashSet;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let mut set = nums.into_iter().collect::<HashSet<_>>();
        let mut max_count = 0;
        
        while let Some(num1) = set.iter().copied().next() {
            let mut count = 0;
            let mut num2  = num1;
            while set.remove(&num2) {
                num2 -= 1;
                count += 1;
            }
            num2 = num1 + 1;
            while set.remove(&num2) {
                num2 += 1;
                count += 1;
            }
            max_count = max_count.max(count);
        }

        max_count
    }
}