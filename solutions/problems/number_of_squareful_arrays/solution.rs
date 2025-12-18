impl Solution {
    pub fn num_squareful_perms(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();
        let mut used = vec![false; nums.len()];
        let mut count = 0;
        
        Self::backtrack(&nums, &mut used, &mut Vec::new(), &mut count);
        count
    }
    
    fn is_perfect_square(n: i32) -> bool {
        let root = (n as f64).sqrt() as i32;
        root * root == n
    }
    
    fn backtrack(nums: &[i32], used: &mut Vec<bool>, 
                 current: &mut Vec<i32>, count: &mut i32) {
        if current.len() == nums.len() {
            *count += 1;
            return;
        }
        
        for i in 0..nums.len() {
            if used[i] {
                continue;
            }
            
            // Skip duplicates
            if i > 0 && nums[i] == nums[i-1] && !used[i-1] {
                continue;
            }
            
            // Check squareful condition
            if !current.is_empty() && !Self::is_perfect_square(current.last().unwrap() + nums[i]) {
                continue;
            }
            
            used[i] = true;
            current.push(nums[i]);
            Self::backtrack(nums, used, current, count);
            current.pop();
            used[i] = false;
        }
    }
}