impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        // บันทึกตำแหน่งสุดท้ายของแต่ละตัวอักษร
        let mut last = [0; 26];
        for (i, c) in s.chars().enumerate() {
            last[(c as u8 - b'a') as usize] = i;
        }
        
        let mut result = Vec::new();
        let mut start = 0;  // จุดเริ่มต้นของส่วนปัจจุบัน
        let mut end = 0;    // จุดสิ้นสุดของส่วนปัจจุบัน
        
        for (i, c) in s.chars().enumerate() {
            // ขยายขอบเขตให้ครอบคลุมตำแหน่งสุดท้ายของตัวอักษรนี้
            let char_index = (c as u8 - b'a') as usize;
            end = end.max(last[char_index]);
            
            // ถ้าถึงจุดสิ้นสุดของส่วนปัจจุบัน
            if i == end {
                result.push((end - start + 1) as i32);  // บันทึกความยาว
                start = i + 1;  // เริ่มส่วนใหม่
            }
        }
        
        result
    }
}