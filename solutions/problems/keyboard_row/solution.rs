impl Solution {
    pub fn find_words(words: Vec<String>) -> Vec<String> {
        // สร้าง HashSet สำหรับแต่ละแถว
        use std::collections::HashSet;
        
        let row1: HashSet<char> = "qwertyuiop".chars().collect();
        let row2: HashSet<char> = "asdfghjkl".chars().collect();
        let row3: HashSet<char> = "zxcvbnm".chars().collect();
        
        let mut result = Vec::new();
        
        for word in words {
            // ตรวจสอบแถวของตัวอักษรตัวแรก
            let first_char = word.chars().next().unwrap().to_ascii_lowercase();
            let row = if row1.contains(&first_char) {
                &row1
            } else if row2.contains(&first_char) {
                &row2
            } else {
                &row3
            };
            
            // ตรวจสอบว่าทุกตัวอักษรอยู่ในแถวเดียวกัน
            let all_same_row = word.chars()
                .all(|c| row.contains(&c.to_ascii_lowercase()));
            
            if all_same_row {
                result.push(word);
            }
        }
        
        result
    }
}