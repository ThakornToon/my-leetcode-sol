use std::collections::HashMap;

impl Solution {
    pub fn check_strings(s1: String, s2: String) -> bool {
        let s1 = s1.as_bytes();
        let s2 = s2.as_bytes();
        let n = s1.len();
        
        let mut even_count_s1 = HashMap::new();
        let mut even_count_s2 = HashMap::new();
        let mut odd_count_s1 = HashMap::new();
        let mut odd_count_s2 = HashMap::new();
        
        for i in 0..n {
            if i % 2 == 0 {
                *even_count_s1.entry(s1[i]).or_insert(0) += 1;
                *even_count_s2.entry(s2[i]).or_insert(0) += 1;
            } else {
                *odd_count_s1.entry(s1[i]).or_insert(0) += 1;
                *odd_count_s2.entry(s2[i]).or_insert(0) += 1;
            }
        }
        
        even_count_s1 == even_count_s2 && odd_count_s1 == odd_count_s2
    }
}