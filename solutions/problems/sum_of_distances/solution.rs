use std::collections::HashMap;

impl Solution {
    pub fn distance(nums: Vec<i32>) -> Vec<i64> {
        let n = nums.len();
        let mut result = vec![0; n];
        
        // Group indices by value
        let mut groups: HashMap<i32, Vec<usize>> = HashMap::new();
        for (i, &val) in nums.iter().enumerate() {
            groups.entry(val).or_insert(Vec::new()).push(i);
        }
        
        // For each group, calculate sum of distances
        for (_, indices) in groups.iter() {
            let m = indices.len();
            if m == 1 { continue; }
            
            // Calculate prefix sum
            let mut prefix = vec![0; m + 1];
            for i in 0..m {
                prefix[i + 1] = prefix[i] + indices[i] as i64;
            }
            
            // Calculate distance sum for each index
            for i in 0..m {
                let idx = indices[i] as i64;
                let left_sum = (i as i64) * idx - prefix[i];
                let right_sum = (prefix[m] - prefix[i + 1]) - ((m - i - 1) as i64) * idx;
                result[indices[i]] = left_sum + right_sum;
            }
        }
        
        result
    }
}