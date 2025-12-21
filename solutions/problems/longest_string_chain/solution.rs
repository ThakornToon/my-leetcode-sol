use std::collections::HashMap;
use std::cmp;
impl Solution {
    pub fn longest_str_chain(words: Vec<String>) -> i32 {
        let mut words = words;
        // เรียงตามความยาว
        words.sort_by(|a, b| a.len().cmp(&b.len()));
        
        let mut dp: HashMap<String, i32> = HashMap::new();
        let mut max_length = 0;
        
        for word in &words {
            let mut best = 1;  // chain ที่จบด้วยคำปัจจุบัน
            
            // ลองลบหนึ่งตัวอักษร
            for i in 0..word.len() {
                let predecessor = format!("{}{}", 
                    &word[0..i], 
                    &word[i+1..]);

                // ดูว่ามีคำนั้นไหม
                if let Some(&len) = dp.get(&predecessor) {
                    best = cmp::max(best, len + 1);
                }
            }
            
            dp.insert(word.clone(), best);
            max_length = cmp::max(max_length, best);
        }
        
        max_length
    }
}