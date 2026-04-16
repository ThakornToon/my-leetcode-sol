impl Solution {
    pub fn find_the_longest_substring(s: String) -> i32 {
        let mut first_pos = vec![-1; 32];
        let mut mask = 0;
        let mut max_len = 0;
        first_pos[0] = 0;
        
        for (i, c) in s.chars().enumerate() {
            mask ^= match c {
                'a' => 1 << 0,
                'e' => 1 << 1,
                'i' => 1 << 2,
                'o' => 1 << 3,
                'u' => 1 << 4,
                _ => 0,
            };
            
            if first_pos[mask] != -1 {
                max_len = max_len.max(i + 1 - first_pos[mask] as usize);
            } else {
                first_pos[mask] = (i + 1) as i32;
            }
        }
        
        max_len as i32
    }
}