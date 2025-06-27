impl Solution {
    pub fn max_product(words: Vec<String>) -> i32 {
        let masks: Vec<u32> = words.iter()
            .map(|word| {
                word.chars().fold(0, |mask, c| mask | (1 << (c as u8 - b'a')))
            })
            .collect();
        
        let mut max_prod = 0;
        
        // เปรียบเทียบทุกคู่ของคำ
        for i in 0..words.len() {
            for j in i+1..words.len() {
                if masks[i] & masks[j] == 0 {
                    max_prod = max_prod.max(words[i].len() * words[j].len());
                }
            }
        }
        
        max_prod as i32
    }
}