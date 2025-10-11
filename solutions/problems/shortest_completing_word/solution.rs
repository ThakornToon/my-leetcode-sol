impl Solution {
    pub fn shortest_completing_word(license_plate: String, words: Vec<String>) -> String {
        // Build frequency map from license plate
        let mut license_count = [0; 26];
        for c in license_plate.chars() {
            if c.is_ascii_alphabetic() {
                license_count[(c.to_ascii_lowercase() as u8 - b'a') as usize] += 1;
            }
        }
        
        let mut result = String::new();
        
        for word in words {
            // Build frequency map for current word
            let mut word_count = [0; 26];
            for c in word.chars() {
                word_count[(c as u8 - b'a') as usize] += 1;
            }
            
            // Check if word contains all required letters
            let valid = (0..26).all(|i| word_count[i] >= license_count[i]);
            
            // Update result if valid and shorter
            if valid && (result.is_empty() || word.len() < result.len()) {
                result = word;
            }
        }
        
        result
    }
}