impl Solution {
    pub fn count_characters(words: Vec<String>, chars: String) -> i32 {
        // นับความถี่ตัวอักษรใน chars
        let mut char_count = [0; 26];
        for c in chars.chars() {
            char_count[(c as u8 - b'a') as usize] += 1;
        }
        
        let mut total_length = 0;
        
        for word in words {
            // สำเนา char_count
            let mut temp_count = char_count;
            let mut can_form = true;
            
            // ตรวจสอบแต่ละตัวอักษรในคำ
            for c in word.chars() {
                let idx = (c as u8 - b'a') as usize;
                if temp_count[idx] == 0 {
                    can_form = false;
                    break;
                }
                temp_count[idx] -= 1;
            }
            
            if can_form {
                total_length += word.len() as i32;
            }
        }
        
        total_length
    }
}