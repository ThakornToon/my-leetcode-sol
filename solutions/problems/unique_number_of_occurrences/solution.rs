use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool {
        // 1. นับความถี่
        let mut freq = HashMap::new();
        for &num in &arr {
            *freq.entry(num).or_insert(0) += 1;
        }
        
        // 2. ตรวจสอบความถี่ที่ไม่ซ้ำ
        let mut seen = HashSet::new();
        for &count in freq.values() {
            if seen.contains(&count) {
                return false;
            }
            seen.insert(count);
        }
        
        true

    }
}