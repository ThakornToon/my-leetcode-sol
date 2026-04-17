use std::collections::HashMap;

impl Solution {
    pub fn find_lucky(arr: Vec<i32>) -> i32 {
        let mut freq = HashMap::new();
        
        for &num in &arr {
            *freq.entry(num).or_insert(0) += 1;
        }
        
        let mut max_lucky = -1;
        for (&val, &count) in &freq {
            if val == count && val > max_lucky {
                max_lucky = val;
            }
        }
        
        max_lucky
    }
}