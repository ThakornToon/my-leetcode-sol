impl Solution {
    pub fn num_smaller_by_frequency(queries: Vec<String>, words: Vec<String>) -> Vec<i32> {
        // f(s) ≤ 10 (เพราะ string ยาวไม่เกิน 10)
        let mut freq_count = [0; 11];  // index 0-10
        
        // คำนวณ frequency สำหรับ words
        for word in &words {
            let f = Self::calculate_f(word) as usize;
            freq_count[f] += 1;
        }
        
        // สร้าง suffix sum
        let mut suffix_sum = [0; 12];  // ขนาด 12 เพื่อให้ suffix_sum[11]=0
        for i in (1..=10).rev() {
            suffix_sum[i] = suffix_sum[i + 1] + freq_count[i];
        }
        
        queries.iter()
            .map(|query| {
                let query_f = Self::calculate_f(query) as usize;
                suffix_sum[query_f + 1] as i32
            })
            .collect()
    }
    
    fn calculate_f(s: &str) -> i32 {
        let bytes = s.as_bytes();
        let mut smallest = b'z';
        let mut count = 0;
        
        for &c in bytes {
            if c < smallest {
                smallest = c;
                count = 1;
            } else if c == smallest {
                count += 1;
            }
        }
        
        count as i32
    }
}