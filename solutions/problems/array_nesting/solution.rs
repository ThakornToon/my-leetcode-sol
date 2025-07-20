impl Solution {
    pub fn array_nesting(nums: Vec<i32>) -> i32 {
        let mut visited = vec![false; nums.len()];
        let mut max_length = 0;
        
        for i in 0..nums.len() {
            if !visited[i] {
                let mut start = nums[i] as usize;
                let mut count = 0;
                
                loop {
                    start = nums[start] as usize;
                    count += 1;
                    visited[start] = true;
                    
                    if start == nums[i] as usize {
                        break;
                    }
                }
                
                max_length = max_length.max(count);
            }
        }
        
        max_length
    }
}