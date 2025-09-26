use std::cmp::max;
impl Solution {
    pub fn strong_password_checker(password: String) -> i32 {
        let mut has_lower = false;
        let mut has_upper = false;
        let mut has_digit = false;
        let char_len = password.len();
        let chars: Vec<char> = password.chars().collect();
        
        for &c in &chars {
            if c >= 'a' && c <= 'z' {
                has_lower = true;
            } else if c >= 'A' && c <= 'Z' {
                has_upper = true;
            } else if c >= '0' && c <= '9' {
                has_digit = true;
            }
        }

        let missing_types = 3 - (has_lower as i32 + has_upper as i32 + has_digit as i32);
        let mut repeats: Vec<i32> = Vec::new();
        
        let mut i = 0;
        while i < char_len {
            let mut j = i;
            while j < char_len && chars[j] == chars[i] {
                j += 1;
            }
            let length = (j - i) as i32;
            if length >= 3 {
                repeats.push(length);
            }
            i = j;
        }

        if char_len < 6 {
            return max(6 - char_len as i32, missing_types);
        } 
        else if char_len <= 20 {
            let mut replace = 0;
            for &len in &repeats {
                replace += len / 3;
            }
            return max(replace, missing_types);
        } else {
            let mut over_len = char_len as i32 - 20;
            let delete_count = over_len;
            
            // First pass: delete 1 from sequences with len % 3 == 0
            for k in 0..repeats.len() {
                if over_len <= 0 { break; }
                if repeats[k] % 3 == 0 {
                    repeats[k] -= 1;
                    over_len -= 1;
                }
            }
            
            // Second pass: delete 2 from sequences with len % 3 == 1
            for k in 0..repeats.len() {
                if over_len < 2 { break; }
                if repeats[k] % 3 == 1 {
                    repeats[k] -= 2;
                    over_len -= 2;
                }
            }
            
            // Third pass: delete 3 from other sequences
            for k in 0..repeats.len() {
                while repeats[k] >= 3 && over_len >= 3 {
                    repeats[k] -= 3;
                    over_len -= 3;
                }
            }
            
            // Calculate remaining replacements needed
            let mut replace = 0;
            for &len in &repeats {
                if len >= 3 {
                    replace += len / 3;
                }
            }
            
            return delete_count + max(replace, missing_types);
        }
    }
}