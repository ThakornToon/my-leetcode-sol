impl Solution {
    pub fn find_substring_in_wrapround_string(s: String) -> i32 {
        let mut max_len = [0; 26]; // เก็บความยาวสูงสุดที่ลงท้ายด้วยแต่ละตัวอักษร
        let mut current_max = 0;
        let s = s.as_bytes();
        
        for i in 0..s.len() {
            if i > 0 && (s[i] as i32 - s[i-1] as i32 == 1 || s[i-1] as i32 - s[i] as i32 == 25) {
                current_max += 1;
            } else {
                current_max = 1;
            }
            
            let index = (s[i] - b'a') as usize;
            if current_max > max_len[index] {
                max_len[index] = current_max;
            }
        }
        
        max_len.iter().sum()
    }
}