impl Solution {
    pub fn find_and_replace_pattern(words: Vec<String>, pattern: String) -> Vec<String> {
        let mut result = Vec::new();
        let pattern_normalized = Self::normalize(&pattern);
        
        for word in words {
            if Self::normalize(&word) == pattern_normalized {
                result.push(word);
            }
        }
        
        result
    }
    
    fn normalize(s: &str) -> Vec<i32> {
        use std::collections::HashMap;
        
        let mut mapping = HashMap::new();
        let mut normalized = Vec::new();
        let mut next_id = 0;
        
        for ch in s.chars() {
            let id = match mapping.get(&ch) {
                Some(&existing_id) => existing_id,  // มีอยู่แล้ว
                None => {
                    let new_id = next_id;
                    mapping.insert(ch, new_id);
                    next_id += 1;
                    new_id
                }
            };
            normalized.push(id);
        }
        
        normalized
    }
}