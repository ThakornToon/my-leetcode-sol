impl Solution {
    pub fn uncommon_from_sentences(s1: String, s2: String) -> Vec<String> {
        use std::collections::HashMap;
        
        // รวมและ split คำ
        let combined = format!("{} {}", s1, s2);
        let words: Vec<&str> = combined.split_whitespace().collect();
        
        // นับความถี่
        let mut freq = HashMap::new();
        for &word in &words {
            *freq.entry(word).or_insert(0) += 1;
        }
        
        // เก็บคำที่ปรากฏครั้งเดียว
        let mut result = Vec::new();
        for (word, &count) in &freq {
            if count == 1 {
                result.push(word.to_string());
            }
        }
        
        result
    }
}