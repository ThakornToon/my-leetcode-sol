impl Solution {
    pub fn backspace_compare(s: String, t: String) -> bool {
        Self::process_string(&s) == Self::process_string(&t)
    }
    
    fn process_string(s: &str) -> String {
        let mut stack = Vec::new();
        
        for c in s.chars() {
            if c == '#' {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        
        stack.iter().collect()
    }
}