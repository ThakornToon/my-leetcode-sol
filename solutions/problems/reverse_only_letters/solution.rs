impl Solution {
    pub fn reverse_only_letters(s: String) -> String {
        let mut chars: Vec<char> = s.chars().collect();
        let mut left = 0;
        let mut right = chars.len() as i32 - 1;
        
        while left < right {
            let left_char = chars[left as usize];
            let right_char = chars[right as usize];
            
            if !left_char.is_ascii_alphabetic() {
                left += 1;
            } else if !right_char.is_ascii_alphabetic() {
                right -= 1;
            } else {
                chars.swap(left as usize, right as usize);
                left += 1;
                right -= 1;
            }
        }
        
        chars.into_iter().collect()
    }
}