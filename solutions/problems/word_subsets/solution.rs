impl Solution {
    pub fn word_subsets(words1: Vec<String>, words2: Vec<String>) -> Vec<String> {
        // ฟังก์ชันนับความถี่ของตัวอักษร
        fn count_freq(word: &str) -> [usize; 26] {
            let mut freq = [0; 26];
            for c in word.chars() {
                freq[(c as u8 - b'a') as usize] += 1;
            }
            freq
        }
        
        // คำนวณความถี่สูงสุดจาก words2
        let mut max_freq = [0; 26];
        
        for word in &words2 {
            let freq = count_freq(word);
            for i in 0..26 {
                max_freq[i] = max_freq[i].max(freq[i]);
            }
        }
        
        // ตรวจสอบว่า words1 แต่ละคำเป็น universal หรือไม่
        let mut result = Vec::new();
        
        for word in &words1 {
            let freq = count_freq(word);
            let mut valid = true;
            
            for i in 0..26 {
                if freq[i] < max_freq[i] {
                    valid = false;
                    break;
                }
            }
            
            if valid {
                result.push(word.to_string());
            }
        }
        
        result
    }
}