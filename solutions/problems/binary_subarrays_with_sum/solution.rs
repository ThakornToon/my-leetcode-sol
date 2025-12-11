impl Solution {
    pub fn num_subarrays_with_sum(nums: Vec<i32>, goal: i32) -> i32 {
        use std::collections::HashMap;
        
        let mut count = HashMap::new();
        count.insert(0, 1);  // prefix sum = 0 มี 1 วิธี
        
        let mut prefix_sum = 0;
        let mut result = 0;
        
        for &num in &nums {
            prefix_sum += num;
            
            // เราต้องการหา count[prefix_sum - goal]
            if let Some(&c) = count.get(&(prefix_sum - goal)) {
                result += c;
            }
            
            *count.entry(prefix_sum).or_insert(0) += 1;
        }
        
        result
    }
}