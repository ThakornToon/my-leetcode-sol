impl Solution {
    fn is_subsequence(word: &str, s: &str) -> bool {
        let mut word_chars = word.chars();
        let mut current_char = word_chars.next();
        
        for c in s.chars() {
            if let Some(wc) = current_char {
                if wc == c {
                    current_char = word_chars.next();
                }
            } else {
                break;
            }
        }
        
        current_char.is_none()
    }

    pub fn find_longest_word(s: String, dictionary: Vec<String>) -> String {
        let mut sorted_dict = dictionary;
        // เรียงตามความยาวจากมากไปน้อย และตามลำดับพจนานุกรม
        sorted_dict.sort_by(|a, b| {
            if a.len() != b.len() {
                b.len().cmp(&a.len())
            } else {
                a.cmp(b)
            }
        });
        
        for word in sorted_dict {
            if Self::is_subsequence(&word, &s) {
                return word;
            }
        }
        
        String::new()
    }
}