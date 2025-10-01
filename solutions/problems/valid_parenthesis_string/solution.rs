impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let chars: Vec<char> = s.chars().collect();
        
        // Left to right: treat '*' as '('
        let mut balance = 0;
        for &c in &chars {
            if c == '(' || c == '*' {
                balance += 1;
            } else {
                balance -= 1;
            }
            if balance < 0 {
                return false;
            }
        }
        
        // Right to left: treat '*' as ')'
        balance = 0;
        for &c in chars.iter().rev() {
            if c == ')' || c == '*' {
                balance += 1;
            } else {
                balance -= 1;
            }
            if balance < 0 {
                return false;
            }
        }
        
        true
    }
}