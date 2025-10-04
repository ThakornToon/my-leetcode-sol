use std::collections::HashMap;
use std::cmp::{min, max};

impl Solution {
    pub fn find_shortest_sub_array(nums: Vec<i32>) -> i32 {
        let mut map: HashMap<i32, Vec<i32>> = HashMap::new();
        let mut max_degree = 0;
        
        // Build map in one pass - [count, first, last]
        for (i, &num) in nums.iter().enumerate() {
            let entry = map.entry(num).or_insert(vec![0, i as i32, i as i32]);
            entry[0] += 1;        // count
            entry[2] = i as i32;  // last position
            
            max_degree = max(max_degree, entry[0]);
        }
        
        // Find shortest subarray length
        let mut min_length = i32::MAX;
        
        for info in map.values() {
            if info[0] == max_degree {
                let length = info[2] - info[1] + 1;
                min_length = min(min_length, length);
            }
        }
        
        min_length
    }
}