impl Solution {
    pub fn max_score_words(words: Vec<String>, letters: Vec<char>, score: Vec<i32>) -> i32 {
        // นับความถี่ของตัวอักษรที่มี
        let mut available = vec![0; 26];
        for c in letters {
            available[(c as u8 - b'a') as usize] += 1;
        }
        
        let n = words.len();
        let mut max_score = 0;
        
        // ทดสอบทุก subset (2^n)
        for mask in 0..(1 << n) {
            let mut used = vec![0; 26];
            let mut current_score = 0;
            
            // ตรวจสอบแต่ละคำใน subset
            for i in 0..n {
                if mask & (1 << i) != 0 {
                    let word = &words[i];
                    
                    // นับตัวอักษรที่ต้องใช้
                    // เพิ่มคะแนน
                    for c in word.chars() {
                        used[(c as u8 - b'a') as usize] += 1;
                        current_score += score[(c as u8 - b'a') as usize];
                    }
                }
            }
            
            // ตรวจสอบว่ามีตัวอักษรพอ
            let mut valid = true;
            for i in 0..26 {
                if used[i] > available[i] {
                    valid = false;
                    break;
                }
            }
            
            if valid && current_score > max_score {
                max_score = current_score;
            }
        }
        
        max_score
    }
}