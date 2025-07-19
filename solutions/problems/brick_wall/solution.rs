use std::collections::HashMap;

impl Solution {
    pub fn least_bricks(wall: Vec<Vec<i32>>) -> i32 {
        let mut edge_count = HashMap::new();
        let mut max_count = 0;
        
        for row in &wall {
            let mut sum = 0;
            for brick in &row[..row.len() - 1] {
                sum += brick;
                let count = edge_count.entry(sum).or_insert(0);
                *count += 1;
                if *count > max_count {
                    max_count = *count;
                }
            }
        }
        
        (wall.len() as i32) - max_count
    }
}