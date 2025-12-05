impl Solution {
    pub fn decode_at_index(s: String, k: i32) -> String {
        let mut k = k as i64;
        let mut length: i64 = 0;
        let bytes = s.as_bytes();
        
        // คำนวณ total length
        for &c in bytes {
            if c.is_ascii_digit() {
                length *= (c - b'0') as i64;
            } else {
                length += 1;
            }
        }
        
        // เดินจากหลังมาหน้า
        for &c in bytes.iter().rev() {  
            if c.is_ascii_digit() {
                let d = (c - b'0') as i64;
                length /= d;
                k %= length;
                if k == 0 {
                    k = length;
                }
            } else {
                if k == length {
                    return (c as char).to_string();
                }
                length -= 1;
            }
        }
        
        "".to_string()
    }
}