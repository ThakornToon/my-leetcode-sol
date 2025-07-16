use std::collections::HashMap;

impl Solution {
    pub fn find_pairs(nums: Vec<i32>, k: i32) -> i32 {
        let mut count = 0;
        let mut freq = HashMap::new();
        
        // สร้าง frequency map
        for &num in &nums {
            *freq.entry(num).or_insert(0) += 1;
        }
        
        if k == 0 {
            // นับตัวเลขที่ปรากฏมากกว่า 1 ครั้ง
            for (&num, &cnt) in &freq {
                if cnt > 1 {
                    count += 1;
                }
            }
        } else {
            // ตรวจสอบ num + k มีใน map หรือไม่
            for (&num, _) in &freq {
                if freq.contains_key(&(num + k)) {
                    count += 1;
                }
            }
        }
        
        count
    }
}