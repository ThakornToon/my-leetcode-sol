use std::collections::HashMap;

impl Solution {
    pub fn find_num_of_valid_words(words: Vec<String>, puzzles: Vec<String>) -> Vec<i32> {
        let mut freq: HashMap<u32, i32> = HashMap::new();
        
        // แปลง words เป็น bitmask
        for word in words {
            let mut mask: u32 = 0;
            for c in word.chars() {
                mask |= 1 << (c as u8 - b'a');
            }
            
            // เก็บเฉพาะ word ที่มี ≤ 7 ตัวอักษรต่างกัน
            if mask.count_ones() <= 7 {
                *freq.entry(mask).or_insert(0) += 1;
            }
        }
        
        let mut result = Vec::new();
        
        // ตรวจสอบแต่ละ puzzle
        for puzzle in puzzles {
            let puzzle_chars: Vec<char> = puzzle.chars().collect();
            let first = 1 << (puzzle_chars[0] as u8 - b'a');
            let mut puzzle_mask: u32 = 0;
            
            // สร้าง puzzle mask
            for &c in &puzzle_chars {
                puzzle_mask |= 1 << (c as u8 - b'a');
            }
            
            let mut count = 0;
            let mut subset = puzzle_mask;
            
            // ตรวจสอบทุก subset ของ puzzle mask
            loop {
                if subset & first != 0 {
                    if let Some(&freq_count) = freq.get(&subset) {
                        count += freq_count;
                    }
                }
                
                if subset == 0 {
                    break;
                }
                
                subset = (subset - 1) & puzzle_mask;
            }
            
            result.push(count);
        }
        
        result

    }
}