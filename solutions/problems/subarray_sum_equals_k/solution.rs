use std::collections::HashMap;

impl Solution {
    pub fn subarray_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mut prefix_sums = HashMap::new();
        prefix_sums.insert(0, 1);
        let mut count = 0;
        let mut prefix_sum = 0;
        
        for num in nums {
            prefix_sum += num;
            let find = prefix_sum - k;
            count += prefix_sums.get(&find).unwrap_or(&0);
            *prefix_sums.entry(prefix_sum).or_insert(0) += 1;
        }
        
        count
    }
}