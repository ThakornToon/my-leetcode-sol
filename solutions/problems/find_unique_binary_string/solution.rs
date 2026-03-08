use std::collections::HashSet;


impl Solution {
    pub fn find_different_binary_string(nums: Vec<String>) -> String {
        let seen: HashSet<String> = nums.into_iter().collect();
        let mut current = String::new();
        Self::backtrack(&seen, &mut current, seen.len())
    }

    fn backtrack(seen: &HashSet<String>, current: &mut String, n: usize) -> String {
        if current.len() == n {
            if !seen.contains(current) {
                return current.clone();
            }
            return String::new();
        }
        
        // ลองใส่ '0'
        current.push('0');
        let result = Self::backtrack(seen, current, n);
        if !result.is_empty() { return result; }
        current.pop();
        
        // ลองใส่ '1'
        current.push('1');
        let result = Self::backtrack(seen, current, n);
        if !result.is_empty() { return result; }
        current.pop();
        
        String::new()
    }
}