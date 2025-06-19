impl Solution {
    pub fn find_nth_digit(n: i32) -> i32 {
        let mut n = n as i64;
        let mut digits = 1;      // จำนวนหลักปัจจุบัน (เริ่มจาก 1 หลัก)
        let mut count = 9;       // จำนวนตัวเลขในกลุ่ม digits หลัก
        let mut start = 1;       // ตัวเลขเริ่มต้นของกลุ่ม
        
        // ขั้นตอนที่ 1: หาจำนวนหลักของตัวเลขที่ n อยู่
        while n > digits * count {
            n -= digits * count;
            digits += 1;
            count *= 10;
            start *= 10;
        }
        
        // ขั้นตอนที่ 2: หาตัวเลขที่เฉพาะเจาะจง
        let num = start + (n - 1) / digits;  // ตัวเลขที่ n อยู่
        let digit_index = (n - 1) % digits;   // ตำแหน่งในตัวเลข
        
        // ขั้นตอนที่ 3: หาตัวเลขที่ต้องการ
        num.to_string()
       .chars()
       .nth(digit_index as usize)
       .unwrap()
       .to_digit(10)
       .unwrap() as i32
    }
}