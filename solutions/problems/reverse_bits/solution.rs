impl Solution {
    pub fn reverse_bits(x: u32) -> u32 {
        let mut result = 0;
        for i in 0..32 {
            // เลื่อนผลลัพธ์ไปทางซ้าย
            result <<= 1;
            // เพิ่มบิตสุดท้ายของ x เข้าไปในผลลัพธ์
            result |= (x >> i) & 1;
        }
        result
    }
}