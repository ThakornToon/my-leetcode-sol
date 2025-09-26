impl Solution {
    pub fn check_subarray_sum(nums: Vec<i32>, k: i32) -> bool {
        use std::collections::HashMap;
        let mut remainder_map = HashMap::new();
        remainder_map.insert(0, -1); // Handle case when prefix sum itself is multiple of k
        
        let mut prefix_sum = 0;
        
        for (i, &num) in nums.iter().enumerate() {
            prefix_sum += num;
            let mut remainder = prefix_sum % k;
            
            // Handle negative remainders
            if remainder < 0 {
                remainder += k;
            }
            
            match remainder_map.get(&remainder) {
                Some(&prev_index) => {
                    if i as i32 - prev_index >= 2 {
                        return true;
                    }
                }
                None => {
                    remainder_map.insert(remainder, i as i32);
                }
            }
        }
        
        false
    }
}