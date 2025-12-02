impl Solution {
    pub fn shifting_letters(s: String, shifts: Vec<i32>) -> String {
        let mut bytes: Vec<u8> = s.into_bytes();
        let mut total_shift = 0u32;
        
        // วนจากหลังมาหน้า
        for i in (0..bytes.len()).rev() {
            total_shift = (total_shift + shifts[i] as u32) % 26;
            
            let current = bytes[i] - b'a';
            let shifted = (current as u32 + total_shift) % 26;
            bytes[i] = b'a' + shifted as u8;
        }
        
        String::from_utf8(bytes).unwrap()
    }
}