impl Solution {
    pub fn count_triplets(nums: Vec<i32>) -> i32 {
        const MAX: usize = 1 << 16;
        let mut freq = vec![0; MAX];
        let n = nums.len();
        
        // Count pairwise AND frequencies
        for i in 0..n {
            for j in 0..n {
                let and_val = (nums[i] & nums[j]) as usize;
                freq[and_val] += 1;
            }
        }
        
        let mut count = 0;
        
        // For each nums[k], check all masks
        for k in 0..n {
            let num = nums[k];
            for mask in 0..MAX {
                if (num as usize & mask) == 0 {
                    count += freq[mask];
                }
            }
        }
        
        count
    }
}