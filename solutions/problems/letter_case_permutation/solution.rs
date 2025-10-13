impl Solution {
    pub fn letter_case_permutation(s: String) -> Vec<String> {
        let mut result = Vec::new();
        let chars: Vec<char> = s.chars().collect();
        Self::backtrack(&chars, 0, String::new(), &mut result);
        result
    }
    
    fn backtrack(chars: &[char], index: usize, current: String, result: &mut Vec<String>) {
        if index == chars.len() {
            result.push(current);
            return;
        }
        
        let c = chars[index];
        if c.is_ascii_digit() {
            Self::backtrack(chars, index + 1, current + &c.to_string(), result);
        } else {
            Self::backtrack(chars, index + 1, current.clone() + &c.to_lowercase().to_string(), result);
            Self::backtrack(chars, index + 1, current + &c.to_uppercase().to_string(), result);
        }
    }
}