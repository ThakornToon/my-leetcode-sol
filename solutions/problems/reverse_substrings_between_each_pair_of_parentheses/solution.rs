impl Solution {
    pub fn reverse_parentheses(s: String) -> String {
        let mut stack: Vec<String> = Vec::new();
        let mut current = String::new();
        
        for c in s.chars() {
            match c {
                '(' => {
                    stack.push(current);
                    current = String::new();
                }
                ')' => {
                    current = current.chars().rev().collect();
                    if let Some(prev) = stack.pop() {
                        current = prev + &current;
                    }
                }
                _ => current.push(c)
            }
        }
        
        current
    }
}