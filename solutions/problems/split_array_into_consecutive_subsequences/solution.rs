use std::collections::HashMap;

impl Solution {
    pub fn is_possible(nums: Vec<i32>) -> bool {
        let mut count = HashMap::new();
        let mut end = HashMap::new();
        
        // Count frequency
        for &num in &nums {
            *count.entry(num).or_insert(0) += 1;
        }
        
        for &num in &nums {
            let cnt = count.get_mut(&num).unwrap();
            if *cnt == 0 {
                continue;
            }
            *cnt -= 1;
            
            // Try to append to existing subsequence
            if let Some(e) = end.get_mut(&(num - 1)) {
                if *e > 0 {
                    *e -= 1;
                    *end.entry(num).or_insert(0) += 1;
                    continue;
                }
            }
            
            // Start new subsequence
            if let (Some(c1), Some(c2)) = (count.get(&(num + 1)), count.get(&(num + 2))) {
                if *c1 > 0 && *c2 > 0 {
                    *count.get_mut(&(num + 1)).unwrap() -= 1;
                    *count.get_mut(&(num + 2)).unwrap() -= 1;
                    *end.entry(num + 2).or_insert(0) += 1;
                    continue;
                }
            }
            
            return false;
        }
        
        true
    }
}