use std::collections::HashMap;

impl Solution {
    pub fn find_max_length(nums: Vec<i32>) -> i32 {
        let mut prefix_map = HashMap::new();
        prefix_map.insert(0, -1); // prefix sum = 0 ที่ index -1
        
        let mut max_len = 0;
        let mut sum = 0;
        
        for (i, &num) in nums.iter().enumerate() {
            // แปลง 0 เป็น -1, 1 เป็น 1
            sum += if num == 0 { -1 } else { 1 };
            
            match prefix_map.get(&sum) {
                Some(&prev_index) => {
                    // พบ prefix sum ซ้ำ → คำนวณความยาว
                    max_len = max_len.max(i as i32 - prev_index);
                },
                None => {
                    // เก็บตำแหน่งแรกของ prefix sum นี้
                    prefix_map.insert(sum, i as i32);
                }
            }
        }
        
        max_len
    }
}
