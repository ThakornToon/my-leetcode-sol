use std::collections::HashMap;
impl Solution {
    pub fn most_common_word(paragraph: String, banned: Vec<String>) -> String {
        let mut count = HashMap::new();
        let mut current_word = String::new();
        
        // ดูทีละตัวอักษร
        for c in paragraph.chars() {
            if c.is_ascii_alphabetic() {
                current_word.push(c.to_ascii_lowercase());
            } else if !current_word.is_empty() {
                // เพิ่มจำนวนใน HashMap
                *count.entry(current_word.clone()).or_insert(0) += 1;
                current_word.clear();
            }
        }
        
        // คำสุดท้าย
        if !current_word.is_empty() {
            *count.entry(current_word).or_insert(0) += 1;
        }
        
        // ลบคำต้องห้าม
        for bad_word in banned {
            count.remove(&bad_word);
        }
        
        // หาคำที่พบบ่อยที่สุด
        let mut result = String::new();
        let mut max_count = 0;
        
        for (word, cnt) in count {
            if cnt > max_count {
                max_count = cnt;
                result = word;
            }
        }
        
        result
    }
}