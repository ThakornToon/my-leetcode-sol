impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let mut left = 0;
        let mut max_win = 0;
        let mut most_char = 0;
        let mut ch = [0; 26];
        let s_bytes = s.as_bytes();
        let len = s.len();
        
        for right in 0..len {
            let c = (s_bytes[right] - b'A') as usize;
            ch[c] += 1;
            most_char = most_char.max(ch[c]); // นับจำนวนตัวอักษรที่ซ้ำมากที่สุด โดยหากมีการลบไม่จำเป็นต้องหาใหม่เพราะขนาดหน้าต่างเราจะเท่าเดิม หากจะได้ขนาดหน้าต่างที่มากขึ้นต้องมี mostChar ที่มากขึ้นด้วย
            
            while (right - left + 1 - most_char as usize) > k as usize {
                let left_char = (s_bytes[left] - b'A') as usize;
                ch[left_char] -= 1;
                left += 1;
            }
            
            max_win = max_win.max((right - left + 1) as i32);
        }
        
        max_win
    }
}