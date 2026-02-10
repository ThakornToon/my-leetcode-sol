use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn longest_balanced(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut max_len = 0;
        
        // สำหรับแต่ละ starting point
        for i in 0..n {
            // Early exit
            if n - i <= max_len as usize {
                break;
            }
            
            let mut even_set = HashSet::new();
            let mut odd_set = HashSet::new();
            
            for j in i..n {
                if nums[j] % 2 == 0 {
                    even_set.insert(nums[j]);
                } else {
                    odd_set.insert(nums[j]);
                }
                
                if even_set.len() == odd_set.len() {
                    max_len = max_len.max((j - i + 1) as i32);
                }
            }
        }
        
        max_len
    }
}