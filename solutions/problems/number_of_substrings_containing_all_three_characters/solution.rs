impl Solution {
    pub fn number_of_substrings(s: String) -> i32 {
        let s = s.as_bytes();
        let mut last_pos = [-1, -1, -1];
        let mut result = 0;
        
        for (i, &ch) in s.iter().enumerate() {
            last_pos[(ch - b'a') as usize] = i as i32;
            
            let min_last = *last_pos.iter().min().unwrap();
            if min_last != -1 {
                result += min_last + 1;
            }
        }
        
        result
    }
}