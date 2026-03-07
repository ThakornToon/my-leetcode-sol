impl Solution {
    pub fn freq_alphabets(s: String) -> String {
        let s = s.as_bytes();
        let mut result = Vec::new();
        let mut i = s.len() as i32 - 1;
        
        while i >= 0 {
            if s[i as usize] == b'#' {
                let num = (s[i as usize - 2] - b'0') * 10 + (s[i as usize - 1] - b'0');
                result.push((b'a' + num - 1) as char);
                i -= 3;
            } else {
                let num = s[i as usize] - b'0';
                result.push((b'a' + num - 1) as char);
                i -= 1;
            }
        }
        
        result.into_iter().rev().collect()
    }
}