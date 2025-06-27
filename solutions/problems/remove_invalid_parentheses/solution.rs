impl Solution {
    fn is_valid(s: &str) -> bool {
        let mut balance = 0;
        for c in s.chars() {
            if c == '(' {
                balance += 1;
            } else if c == ')' {
                balance -= 1;
            }
            if balance < 0 {
                return false;
            }
        }
        balance == 0
    }

    fn backtrack(s: &str, start: usize, left_rem: i32, right_rem: i32, result: &mut Vec<String>) {
        if left_rem == 0 && right_rem == 0 {
            if Self::is_valid(s) {
                result.push(s.to_string());
            }
            return;
        }

        let chars: Vec<char> = s.chars().collect();
        for i in start..chars.len() {
            if i > start && chars[i] == chars[i - 1] {
                continue; // skip duplicates
            }
            if chars[i] == '(' && left_rem > 0 {
                let new_str = format!("{}{}", &s[..i], &s[i + 1..]);
                Self::backtrack(&new_str, i, left_rem - 1, right_rem, result);
            }
            if chars[i] == ')' && right_rem > 0 {
                let new_str = format!("{}{}", &s[..i], &s[i + 1..]);
                Self::backtrack(&new_str, i, left_rem, right_rem - 1, result);
            }
        }
    }
    pub fn remove_invalid_parentheses(s: String) -> Vec<String> {
        let mut left_rem = 0;
        let mut right_rem = 0;
        
        for c in s.chars() {
            if c == '(' {
                left_rem += 1;
            } else if c == ')' {
                if left_rem > 0 {
                    left_rem -= 1;
                } else {
                    right_rem += 1;
                }
            }
        }
        
        let mut result = Vec::new();
        Self::backtrack(&s, 0, left_rem, right_rem, &mut result);
        result
    }
}