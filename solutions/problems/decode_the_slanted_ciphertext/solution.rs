impl Solution {
    pub fn decode_ciphertext(encoded_text: String, rows: i32) -> String {
        let rows = rows as usize;
        let len = encoded_text.len();
        let cols = len / rows;
        let bytes = encoded_text.as_bytes();
        
        let mut result = String::new();
        
        // อ่านแนวทแยง
        for start_col in 0..cols {
            let mut r = 0;
            let mut c = start_col;
            while r < rows && c < cols {
                result.push(bytes[r * cols + c] as char);
                r += 1;
                c += 1;
            }
        }
        
        // ตัดช่องว่างท้าย
        while result.ends_with(' ') {
            result.pop();
        }
        
        result
    }
}