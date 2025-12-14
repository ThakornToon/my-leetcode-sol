impl Solution {
    pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
        // สร้าง mapping จาก character ไปยัง order index
        let mut order_map = [0; 26];
        for (i, c) in order.chars().enumerate() {
            order_map[(c as u8 - b'a') as usize] = i;
        }
        
        // เปรียบเทียบทีละคู่ของ words
        for pair in words.windows(2) {
            let word1 = &pair[0];
            let word2 = &pair[1];
            
            let min_len = word1.len().min(word2.len());
            let mut found_difference = false;
            
            // เปรียบเทียบทีละตัวอักษร
            for j in 0..min_len {
                let c1 = word1.as_bytes()[j];
                let c2 = word2.as_bytes()[j];
                
                if c1 != c2 {
                    if order_map[(c1 - b'a') as usize] > order_map[(c2 - b'a') as usize] {
                        return false;
                    }
                    found_difference = true;
                    break;
                }
            }
            
            // ถ้าตัวอักษรทั้งหมดเหมือนกัน แต่ word1 ยาวกว่า word2
            if !found_difference && word1.len() > word2.len() {
                return false;
            }
        }
        
        true
    }
}