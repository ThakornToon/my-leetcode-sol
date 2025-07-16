impl Solution {
    fn is_subsequence(a: &str, b: &str) -> bool {
        let mut a_chars = a.chars();
        let mut current_char = a_chars.next();
        
        for c in b.chars() {
            if let Some(ac) = current_char {
                if ac == c {
                    current_char = a_chars.next();
                }
            } else {
                break;
            }
        }
        
        current_char.is_none()
    }

    pub fn find_lu_slength(strs: Vec<String>) -> i32 {
        use std::collections::HashMap;
    
        let mut count: HashMap<&str, usize> = HashMap::new();
        for s in &strs { // ยืมอยู่
            *count.entry(s).or_insert(0) += 1;
        }
        
        let mut sorted_strs = strs.clone(); // ยืม mut ไม่ได้
        sorted_strs.sort_by(|a, b| b.len().cmp(&a.len())); // เรียงตามความยาวสตริงมากไปน้อย
        
        for (i, s) in sorted_strs.iter().enumerate() {
            if count[s.as_str()] == 1 {
                let mut is_uncommon = true;

                for other in sorted_strs.iter().take(i) { // เมื่อตรวจสอบสตริงที่ตำแหน่ง i เราต้องการตรวจสอบเฉพาะสตริงที่ยาวกว่าหรือเท่ากัน (ซึ่งอยู่ก่อนหน้า i) เท่านั้น
                    if Self::is_subsequence(s, other) {
                        is_uncommon = false;
                        break;
                    }
                }
                if is_uncommon {
                    return s.len() as i32;
                }
            }
        }
        
        -1
    }
}