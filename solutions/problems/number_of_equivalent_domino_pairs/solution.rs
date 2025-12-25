use std::collections::HashMap;

impl Solution {
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
        let mut count = HashMap::new();
        let mut result = 0;
        
        for domino in dominoes {
            let a = domino[0];
            let b = domino[1];
            let key = if a < b { (a, b) } else { (b, a) };
            
            let cnt = count.entry(key).or_insert(0);
            result += *cnt;
            *cnt += 1;
        }
        
        result
    }
}