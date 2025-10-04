impl Solution {
    pub fn has_alternating_bits(n: i32) -> bool {
        // ถ้า bit สลับกัน: n ^ (n >> 1) จะได้เลขที่ทุก bit เป็น 1
        let temp = n ^ (n >> 1);
        // ตรวจสอบว่า temp เป็นเลขที่ทุก bit เป็น 1 โดย (temp & (temp + 1)) == 0
        (temp & (temp + 1)) == 0
    }
}