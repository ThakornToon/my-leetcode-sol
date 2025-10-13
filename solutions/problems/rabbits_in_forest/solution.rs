use std::collections::HashMap;
impl Solution {
    pub fn num_rabbits(answers: Vec<i32>) -> i32 {
        let mut count = HashMap::new();
        
        // นับความถี่
        for &ans in &answers {
            *count.entry(ans).or_insert(0) += 1;
        }
        
        let mut total = 0;
        for (&k, &cnt) in &count {
            let group_size = k + 1;
            let groups = (cnt + group_size - 1) / group_size;
            total += groups * group_size;
        }
        
        total
    }
}