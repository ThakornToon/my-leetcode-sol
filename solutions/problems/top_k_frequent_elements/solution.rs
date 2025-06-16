impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut frequency_map = std::collections::HashMap::new();
        for &num in &nums {
            *frequency_map.entry(num).or_insert(0) += 1;
        }
        
        let max_freq = *frequency_map.values().max().unwrap_or(&0);
        let mut buckets: Vec<Vec<i32>> = vec![vec![]; (max_freq + 1) as usize];
        
        for (num, freq) in frequency_map {
            buckets[freq as usize].push(num);
        }
        
        let mut result = Vec::new();
        for i in (0..buckets.len()).rev() {
            for &num in &buckets[i] {
                result.push(num);
                if result.len() == k as usize {
                    return result;
                }
            }
        }
        
        result
    }
}