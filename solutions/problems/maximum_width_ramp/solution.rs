impl Solution {
    pub fn max_width_ramp(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut stack = Vec::new();
        
        // monotonic decreasing stack (indices)
        for i in 0..n {
            if stack.is_empty() || nums[*stack.last().unwrap()] > nums[i] {
                stack.push(i);
            }
        }
        
        let mut max_width = 0;
        // scan from right to left
        for j in (0..n).rev() {
            while let Some(&i) = stack.last() {
                if nums[i] <= nums[j] {
                    max_width = max_width.max(j - i);
                    stack.pop();
                } else {
                    break;
                }
            }
        }
        
        max_width as i32
    }
}