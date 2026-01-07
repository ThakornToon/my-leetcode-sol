use std::collections::HashMap;

impl Solution {
    pub fn longest_subsequence(arr: Vec<i32>, difference: i32) -> i32 {
        // HashMap เก็บ state: ค่าสุดท้าย -> ความยาวลำดับ
        let mut dp = HashMap::new();
        let mut max_length = 0;
        
        for &num in &arr {
            // คำนวณค่าก่อนหน้าในลำดับ
            let prev = num - difference;
            
            // ดึงความยาวลำดับที่ลงท้ายด้วย prev (ถ้ามี)
            let current_length = dp.get(&prev).copied().unwrap_or(0) + 1;
            
            // บันทึกความยาวลำดับที่ลงท้ายด้วย num
            dp.insert(num, current_length);
            
            // อัพเดทค่าสูงสุด
            max_length = max_length.max(current_length);
        }
        
        max_length
    }
}