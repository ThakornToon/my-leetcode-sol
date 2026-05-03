impl Solution {
    pub fn check_if_can_break(s1: String, s2: String) -> bool {
        let mut s1_chars: Vec<char> = s1.chars().collect();
        let mut s2_chars: Vec<char> = s2.chars().collect();
        
        s1_chars.sort();
        s2_chars.sort();
        
        // ตรวจสอบ s1 >= s2 ทุกตัว
        let s1_ge_s2 = (0..s1_chars.len()).all(|i| s1_chars[i] >= s2_chars[i]);
        // ตรวจสอบ s1 <= s2 ทุกตัว
        let s1_le_s2 = (0..s1_chars.len()).all(|i| s1_chars[i] <= s2_chars[i]);
        
        s1_ge_s2 || s1_le_s2
    }
}