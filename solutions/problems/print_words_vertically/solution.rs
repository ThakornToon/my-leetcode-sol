impl Solution {
    pub fn print_vertically(s: String) -> Vec<String> {
        let words: Vec<&str> = s.split_whitespace().collect();
        let max_len = words.iter().map(|w| w.len()).max().unwrap_or(0);
        
        let mut result = Vec::new();
        
        // สร้าง string แนวตั้ง
        for j in 0..max_len {
            let mut col = String::new();
            
            for word in &words {
                if j < word.len() {
                    col.push(word.chars().nth(j).unwrap());
                } else {
                    col.push(' ');
                }
            }
            
            // ตัดช่องว่างท้าย
            while col.ends_with(' ') {
                col.pop();
            }
            
            result.push(col);
        }
        
        result
    }
}