impl Solution {
    pub fn unique_letter_string(s: String) -> i32 {
        let n = s.len();
        let mut positions: Vec<Vec<usize>> = vec![Vec::new(); 26];
        let bytes = s.as_bytes();
        
        // เก็บตำแหน่งของแต่ละตัวอักษร
        for (i, &byte) in bytes.iter().enumerate() {
            let c = (byte - b'A') as usize;
            positions[c].push(i);
        }
        
        let mut result = 0;
        
        // สำหรับแต่ละตัวอักษร
        for c in 0..26 {
            let m = positions[c].len();
            
            // สำหรับแต่ละตำแหน่งของตัวอักษรนี้
            for i in 0..m {
                let current = positions[c][i];
                
                // ตำแหน่งก่อนหน้า (หรือ -1 ถ้าไม่มี)
                let prev = if i > 0 { 
                    positions[c][i - 1] as i32 
                } else { 
                    -1 
                };
                
                // ตำแหน่งถัดไป (หรือ n ถ้าไม่มี)
                let next = if i < m - 1 { 
                    positions[c][i + 1] as i32 
                } else { 
                    n as i32 
                };
                
                // จำนวน substring ที่ตัวอักษรนี้เป็น unique
                let left = current as i32 - prev;
                let right = next - current as i32;
                result += left * right;
            }
        }
        
        result
    }
}