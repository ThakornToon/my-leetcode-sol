impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let chars: Vec<char> = s.chars().collect();
        let mut left_idx = 0;
        let mut right_idx = chars.len() - 1;

        while left_idx < right_idx {
            while left_idx < right_idx && !chars[left_idx].is_alphanumeric() {
                left_idx += 1;
            }
            while left_idx < right_idx && !chars[right_idx].is_alphanumeric() {
                right_idx -= 1;
            }
            if left_idx < right_idx {
                if chars[left_idx].to_ascii_lowercase() != chars[right_idx].to_ascii_lowercase() {
                    return false;
                }
                left_idx += 1;
                right_idx -= 1;
            }
        }

        return true;
    }
}