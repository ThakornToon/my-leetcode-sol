impl Solution {
    pub fn unique_morse_representations(words: Vec<String>) -> i32 {
        let morse = vec![
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
            "....", "..", ".---", "-.-", ".-..", "--", "-.",
            "---", ".--.", "--.-", ".-.", "...", "-", "..-",
            "...-", ".--", "-..-", "-.--", "--.."
        ];
        
        let mut unique_codes = std::collections::HashSet::new();
        
        for word in words {
            let mut morse_code = String::new();
            for c in word.chars() {
                let index = (c as u8 - b'a') as usize;
                morse_code.push_str(morse[index]);
            }
            unique_codes.insert(morse_code);
        }
        
        unique_codes.len() as i32
    }
}