impl Solution {
    // Binary Search + Sliding Window
    pub fn smallest_distance_pair(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums;
        nums.sort();
        
        let n = nums.len();
        let mut left = 0;
        let mut right = nums[n - 1] - nums[0];
        
        while left < right {
            let mid = left + (right - left) / 2;
            let count = Self::count_pairs(&nums, mid);
            
            if count < k {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        left
    }
    
    // Count pairs with distance <= target
    fn count_pairs(nums: &[i32], target: i32) -> i32 {
        let mut count = 0;
        let mut left = 0;
        let n = nums.len();
        
        for right in 0..n {
            // Shrink window from left
            while nums[right] - nums[left] > target {
                left += 1;
            }
            // All pairs from left to right-1 with right are valid
            count += (right - left) as i32;
        }
        
        count
    }
}