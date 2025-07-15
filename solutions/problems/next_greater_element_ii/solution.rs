impl Solution {
    pub fn next_greater_elements(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut result = vec![-1; n];
        let mut stack = Vec::new();
        
        for i in 0..2 * n {
            let current_idx = i % n;
            
            while let Some(&top) = stack.last() {
                if nums[current_idx] > nums[top] {
                    result[stack.pop().unwrap()] = nums[current_idx];
                } else {
                    break;
                }
            }
            
            if i < n {
                stack.push(current_idx);
            }
        }
        
        result
    }
}