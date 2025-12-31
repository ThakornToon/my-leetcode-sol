impl Solution {
    pub fn remove_duplicates(s: String, k: i32) -> String {
        let k = k as usize;
        let mut stack: Vec<(u8, usize)> = Vec::new();
        let bytes = s.as_bytes();
        
        for &b in bytes {
            match stack.last_mut() {
                Some((last_byte, count)) if *last_byte == b => {
                    *count += 1;
                    if *count == k {
                        stack.pop();
                    }
                }
                _ => {
                    stack.push((b, 1));
                }
            }
        }
        
        // สร้างผลลัพธ์
        let mut result = Vec::new();
        for (b, count) in stack {
            for _ in 0..count {
                result.push(b);
            }
        }
        
        String::from_utf8(result).unwrap()
    }
}