use std::collections::HashMap;

impl Solution {
    pub fn frequency_sort(s: String) -> String {
        let mut freq_map = HashMap::new();
    
        // นับความถี่
        for c in s.chars() {
            *freq_map.entry(c).or_insert(0) += 1;
        }
        
        // แปลงเป็น vector และเรียงลำดับ
        let mut freq_vec: Vec<(char, usize)> = freq_map.into_iter().collect();
        freq_vec.sort_by(|a, b| b.1.cmp(&a.1));
        
        // สร้างสตริงผลลัพธ์
        let mut result = String::new();
        for (c, count) in freq_vec {
            result.push_str(&c.to_string().repeat(count));
        }
        
        result
    }
}