impl Solution {
    pub fn valid_palindrome(s: String) -> bool {
        let chars = s.as_bytes();
        let mut left = 0;
        let mut right = chars.len() - 1;
        
        while left < right {
            if chars[left] != chars[right] {
                // ลองลบตัวซ้าย หรือ ลองลบตัวขวา
                return Self::is_palindrome(&chars, left + 1, right) ||
                       Self::is_palindrome(&chars, left, right - 1);
            }
            left += 1;
            right -= 1;
        }
        true
    }
    
    fn is_palindrome(chars: &[u8], mut left: usize, mut right: usize) -> bool {
        while left < right {
            if chars[left] != chars[right] {
                return false;
            }
            left += 1;
            right -= 1;
        }
        true
    }
}