impl Solution {
    pub fn distribute_candies(candy_type: Vec<i32>) -> i32 {
        use std::collections::HashSet;
        
        let unique_count = candy_type.iter().collect::<HashSet<_>>().len();
        let max_keep = candy_type.len() / 2;
        
        unique_count.min(max_keep) as i32
    }
}