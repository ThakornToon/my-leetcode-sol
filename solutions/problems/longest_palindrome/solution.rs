use std::collections::HashMap;
impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let mut char_counts = HashMap::new();
        
        // นับความถี่ของแต่ละตัวอักษร
        for c in s.chars() {
            *char_counts.entry(c).or_insert(0) += 1;
        }
        
        let mut length = 0;
        let mut has_odd = false;
        
        // คำนวณความยาวพาลินโดรม
        for &count in char_counts.values() {
            if count % 2 == 0 {
                length += count;
            } else {
                length += count - 1;
                has_odd = true;
            }
        }
        
        // เพิ่ม 1 ถ้ามีตัวอักษรที่ปรากฏจำนวนคี่ครั้ง(ไปไว้ตรงกลาง)
        if has_odd {
            length + 1
        } else {
            length
        }
    }
}