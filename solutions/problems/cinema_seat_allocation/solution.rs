use std::collections::HashMap;

impl Solution {
    pub fn max_number_of_families(n: i32, reserved_seats: Vec<Vec<i32>>) -> i32 {
        let mut reserved: HashMap<i32, u16> = HashMap::new();
        
        for seat in reserved_seats {
            let row = seat[0];
            let col = seat[1] as u16;
            *reserved.entry(row).or_insert(0) |= 1 << col;
        }
        
        let mut total = 0;
        
        for &mask in reserved.values() {
            let mut count = 0;
            
            // ตรวจสอบรูปแบบซ้าย (2-5): bits 2-5
            let left = (mask & 0b111100) == 0;
            // ตรวจสอบรูปแบบกลาง (4-7): bits 4-7
            let middle = (mask & 0b11110000) == 0;
            // ตรวจสอบรูปแบบขวา (6-9): bits 6-9
            let right = (mask & 0b1111000000) == 0;
            
            if left && right {
                count = 2;
            } else if left || middle || right {
                count = 1;
            }
            
            total += count;
        }
        
        // แถวที่ไม่มีการจองเลย
        total += (n - reserved.len() as i32) * 2;
        
        total
    }
}