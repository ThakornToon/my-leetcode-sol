impl Solution {
    pub fn moves_to_make_zigzag(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut pattern1 = 0;  // nums[0] > nums[1] < nums[2] > ...
        let mut pattern2 = 0;  // nums[0] < nums[1] > nums[2] < ...
        
        for i in 0..n {
            let left = if i > 0 { nums[i-1] } else { i32::MAX };
            let right = if i < n-1 { nums[i+1] } else { i32::MAX };
            
            let target = left.min(right) - 1;
            
            if i % 2 == 0 {
            // Pattern 2: Odd indices เป็น peaks  
            // ดังนั้น even indices (0,2,4,...) ควรเป็น valleys
                if nums[i] > target {
                    pattern1 += nums[i] - target;
                }
            } else {
            // Pattern 1: Even indices เป็น peaks
            // ดังนั้น odd indices (1,3,5,...) ควรเป็น valleys
                if nums[i] > target {
                    pattern2 += nums[i] - target;
                }
            }
        }
        
        pattern1.min(pattern2)
    }
}