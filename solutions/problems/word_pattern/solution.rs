use std::collections::HashMap;
impl Solution {
    pub fn word_pattern(pattern: String, s: String) -> bool {
        let mut char_to_word: HashMap<char, &str> = HashMap::new();
        let mut word_to_char: HashMap<&str, char> = HashMap::new();
        
        let words: Vec<&str> = s.split_whitespace().collect();
        let pattern_chars: Vec<char> = pattern.chars().collect();
        
        if words.len() != pattern_chars.len() {
            return false;
        }
        
        for i in 0..pattern_chars.len() {
            let c = pattern_chars[i];
            let w = words[i];
            
            match char_to_word.get(&c) {
                Some(&mapped_word) => {
                    if mapped_word != w {
                        return false;
                    }
                },
                None => {
                    if word_to_char.contains_key(w) {
                        return false;
                    }
                    char_to_word.insert(c, w);
                    word_to_char.insert(w, c);
                }
            }
        }
        
        true
    }
}