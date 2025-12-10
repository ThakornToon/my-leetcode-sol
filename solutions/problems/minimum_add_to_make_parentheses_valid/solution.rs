impl Solution {
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut stack: Vec<char> = Vec::new();
    
        for c in s.chars() {
            match (c, stack.last()) {
                (')', Some('(')) => {
                    stack.pop();
                }
                _ => {
                    stack.push(c);
                }
            }
        }
        
        stack.len() as i32
    }
}