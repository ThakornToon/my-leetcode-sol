impl Solution {
    pub fn max_sum_of_three_subarrays(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let k = k as usize;
        let n = nums.len();
        
        // Calculate window sums
        let mut window = vec![0; n];
        let mut sum = 0;
        for i in 0..n {
            sum += nums[i];
            if i >= k {
                sum -= nums[i - k];
            }
            if i >= k - 1 {
                window[i - k + 1] = sum;
            }
        }
        
        // Left array: best index up to i
        let mut left = vec![0; n];
        let mut best = 0;
        for i in 0..n {
            if window[i] > window[best] {
                best = i;
            }
            left[i] = best;
        }
        
        // Right array: best index from i to end
        let mut right = vec![0; n];
        best = n - 1;
        for i in (0..n).rev() {
            if window[i] >= window[best] {
                best = i;
            }
            right[i] = best;
        }
        
        // Try all middle positions
        let mut result = vec![0, 0, 0];
        let mut max_sum = i32::MIN;
        
        for j in k..=(n - 2 * k) {
            let i = left[j - k];
            let l = right[j + k];
            let total = window[i] + window[j] + window[l];
            
            if total > max_sum {
                max_sum = total;
                result = vec![i as i32, j as i32, l as i32];
            }
        }
        
        result
    }
}