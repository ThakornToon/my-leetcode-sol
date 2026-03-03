use std::collections::HashMap;

impl Solution {
    pub fn max_freq(s: String, max_letters: i32, min_size: i32, max_size: i32) -> i32 {
        let s = s.as_bytes();
        let min_size = min_size as usize;
        let n = s.len();
        let mut count_map = HashMap::new();
        let mut max_count = 0;
        
        // frequency array สำหรับ window ปัจจุบัน
        let mut freq = [0; 26];
        let mut unique = 0;
        
        // ตรวจสอบ window แรก
        for i in 0..min_size {
            let idx = (s[i] - b'a') as usize;
            if freq[idx] == 0 {
                unique += 1;
            }
            freq[idx] += 1;
        }
        
        if unique <= max_letters as usize {
            let substr = s[0..min_size].to_vec();
            let count = count_map.entry(substr).or_insert(0);
            *count += 1;
            max_count = max_count.max(*count);
        }
        
        // ตรวจสอบ window ถัดไป
        for i in 1..=n - min_size {
            // เอาตัวซ้ายออก
            let left_idx = (s[i - 1] - b'a') as usize;
            freq[left_idx] -= 1;
            if freq[left_idx] == 0 {
                unique -= 1;
            }
            
            // เพิ่มตัวขวาใหม่
            let right_idx = (s[i + min_size - 1] - b'a') as usize;
            if freq[right_idx] == 0 {
                unique += 1;
            }
            freq[right_idx] += 1;
            
            if unique <= max_letters as usize {
                let substr = s[i..i + min_size].to_vec();
                let count = count_map.entry(substr).or_insert(0);
                *count += 1;
                max_count = max_count.max(*count);
            }
        }
        
        max_count
    }
}