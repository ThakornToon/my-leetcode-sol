impl Solution {
    pub fn expressive_words(s: String, words: Vec<String>) -> i32 {
        words.iter()
            .filter(|word| Self::is_expressive(&s, word))
            .count() as i32
    }

    fn is_expressive(s: &str, word: &str) -> bool {
        let s_chars: Vec<char> = s.chars().collect();
        let w_chars: Vec<char> = word.chars().collect();
        let (mut i, mut j) = (0, 0);
        
        while i < s_chars.len() && j < w_chars.len() {
            if s_chars[i] != w_chars[j] {
                return false;
            }
            
            // นับกลุ่มใน s
            let s_char = s_chars[i];
            let mut s_count = 0;
            while i < s_chars.len() && s_chars[i] == s_char {
                s_count += 1;
                i += 1;
            }
            
            // นับกลุ่มใน word
            let w_char = w_chars[j];
            let mut w_count = 0;
            while j < w_chars.len() && w_chars[j] == w_char {
                w_count += 1;
                j += 1;
            }
            
            // ตรวจสอบกฎ
            if s_count < w_count || (s_count < 3 && s_count != w_count) {
                return false;
            }
        }
        
        i == s_chars.len() && j == w_chars.len()
    }
}