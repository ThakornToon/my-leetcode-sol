use std::collections::HashMap;

impl Solution {
    pub fn max_equal_freq(nums: Vec<i32>) -> i32 {
        let mut count: HashMap<i32, i32> = HashMap::new();      // num -> frequency
        let mut freq_count: HashMap<i32, i32> = HashMap::new(); // frequency -> count
        let mut max_freq = 0;
        let mut result = 0;
        
        for (i, &num) in nums.iter().enumerate() {
            let current_freq = count.get(&num).unwrap_or(&0); // ความถี่ก่อนหน้านี้ของค่าปัจจุบัน
            
            // ลดความถี่เก่าออกก่อน
            if *current_freq > 0 {
                if let Some(c) = freq_count.get_mut(current_freq) {
                    *c -= 1;
                    if *c == 0 {
                        freq_count.remove(&current_freq);
                    }
                }
            }
            
            // เพิ่มความถี่ใหม่
            *count.entry(num).or_insert(0) += 1;
            let new_freq = count[&num];
            *freq_count.entry(new_freq).or_insert(0) += 1;
            
            // อัปเดตความถี่สูงสุด
            max_freq = max_freq.max(new_freq);
            
            // ตรวจสอบเงื่อนไขที่ถูกต้อง
            let is_valid = {
                // กรณี 1: ความถี่ทั้งหมดเป็น 1
                if max_freq == 1 {
                    true
                }
                // กรณี 2: มีความถี่แบบเดียว
                else if freq_count.len() == 1 && freq_count.get(&max_freq) == Some(&1) {
                    true
                }
                // กรณี 3: มีความถี่ที่แตกต่างกันสองค่า
                else if freq_count.len() == 2 {
                    // ดึง key ทั้งสองจาก map
                    let keys: Vec<&i32> = freq_count.keys().collect();
                    let freq1 = keys[0];
                    let freq2 = keys[1];
                    // กรณีความถี่สูงสุดมากกว่าความถี่ต่ำสุดอยู่ 1 และปรากฏเพียงครั้งเดียว
                    if (max_freq - 1 == *freq1.min(freq2)) && freq_count.get(&max_freq) == Some(&1) {
                        true
                    }
                    // กรณีมีความถี่ 1 ปรากฏเพียงครั้งเดียว
                    else if freq_count.get(&1) == Some(&1) {
                        true
                    } else {
                        false
                    }
                } else {
                    false
                }
            };
            
            // บันทึกผลลัพธ์หากเงื่อนไขถูกต้อง
            if is_valid {
                result = (i + 1) as i32; // ความยาว prefix ณ จุดนี้
            }
        }
        
        result
    }
}