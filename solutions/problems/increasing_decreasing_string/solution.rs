impl Solution {
    pub fn sort_string(s: String) -> String {
        let mut count = [0; 26];
        
        for c in s.chars() {
            count[(c as u8 - b'a') as usize] += 1;
        }
        
        let mut result = String::new();
        
        while result.len() < s.len() {
            // จากน้อยไปมาก
            for i in 0..26 {
                if count[i] > 0 {
                    result.push((b'a' + i as u8) as char);
                    count[i] -= 1;
                }
            }
            
            // จากมากไปน้อย
            for i in (0..26).rev() {
                if count[i] > 0 {
                    result.push((b'a' + i as u8) as char);
                    count[i] -= 1;
                }
            }
        }
        
        result
    }
}