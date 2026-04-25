impl Solution {
    pub fn reformat(s: String) -> String {
        let chars: Vec<char> = s.chars().collect();
        let n = chars.len();
        
        let mut letter_count = 0;
        let mut digit_count = 0;
        
        for &c in &chars {
            if c.is_ascii_alphabetic() {
                letter_count += 1;
            } else {
                digit_count += 1;
            }
        }
        
        if (letter_count as i32 - digit_count as i32).abs() > 1 {
            return String::new();
        }
        
        let mut result = vec![' '; n];
        let mut l_pos;
        let mut d_pos;
        
        if letter_count > digit_count {
            l_pos = 0;
            d_pos = 1;
        } else {
            l_pos = 1;
            d_pos = 0;
        }
        
        for &c in &chars {
            if c.is_ascii_alphabetic() {
                result[l_pos] = c;
                l_pos += 2;
            } else {
                result[d_pos] = c;
                d_pos += 2;
            }
        }
        
        result.into_iter().collect()
    }
}