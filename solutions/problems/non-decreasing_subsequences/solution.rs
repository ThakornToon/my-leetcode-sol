impl Solution {
    pub fn find_subsequences(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let mut current = Vec::new();
        Self::backtrack(&nums, 0, &mut current, &mut result);
        result
    }
    
    fn backtrack(nums: &Vec<i32>, start: usize, current: &mut Vec<i32>, result: &mut Vec<Vec<i32>>) {
        if current.len() >= 2 {
            result.push(current.clone());
        }
        
        let mut used = std::collections::HashSet::new();
        
        for i in start..nums.len() {
            // ตรวจสอบ duplicates
            if used.contains(&nums[i]) {
                continue;
            }
            // ตรวจสอบ non-decreasing
            if !current.is_empty() && nums[i] < *current.last().unwrap() {
                continue;
            }
            
            used.insert(nums[i]);
            current.push(nums[i]);
            Self::backtrack(nums, i + 1, current, result);
            current.pop();
        }
    }
}