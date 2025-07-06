impl Solution {
    pub fn repeated_substring_pattern(s: String) -> bool {
        let len = s.len();
        if len == 1 {
            return false;
        }
        
        for i in 1..=len/2 {
            if len % i != 0 {
                continue;
            }
            
            let pattern = &s[0..i];
            let mut match_found = true;
            
            for j in (i..=(len - i)).step_by(i) {
                if &s[j..j+i] != pattern {
                    match_found = false;
                    break;
                }
            }
            
            if match_found {
                return true;
            }
        }
        
        false
    }
}