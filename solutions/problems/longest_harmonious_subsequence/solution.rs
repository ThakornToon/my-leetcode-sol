use std::collections::HashMap;

impl Solution {
    pub fn find_lhs(nums: Vec<i32>) -> i32 {
        let mut freq = HashMap::new();
        
        // นับความถี่
        for &num in &nums {
            *freq.entry(num).or_insert(0) += 1;
        }
        
        let mut max_length = 0;
        
        // ตรวจสอบคู่ตัวเลขที่ต่างกัน 1
        for (&num, &count) in &freq {
            if let Some(&next_count) = freq.get(&(num + 1)) {
                max_length = max_length.max(count + next_count);
            }
        }
        
        max_length
    }
}