impl Solution {
    pub fn common_chars(words: Vec<String>) -> Vec<String> {
        let mut min_freq = [i32::MAX; 26];
        
        for word in &words {
            let mut freq = [0; 26];
            for c in word.chars() {
                freq[(c as u8 - b'a') as usize] += 1;
            }
            
            for i in 0..26 {
                min_freq[i] = min_freq[i].min(freq[i]);
            }
        }
        
        let mut result = Vec::new();
        for i in 0..26 {
            let c = (b'a' + i as u8) as char;
            for _ in 0..min_freq[i] {
                result.push(c.to_string());
            }
        }
        
        result
    }
}