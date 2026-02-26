impl Solution {
    pub fn num_steps(s: String) -> i32 {
        let mut bytes = s.into_bytes();
        let mut steps = 0;
        
        // ทำงานจนกว่าจะเหลือ "1"
        while !(bytes.len() == 1 && bytes[0] == b'1') {
            steps += 1;
            
            if bytes.last() == Some(&b'0') {
                // เลขคู่: หาร 2 (ลบตัวสุดท้าย)
                bytes.pop();
            } else {
                // เลขคี่: บวก 1
                let mut i = bytes.len() - 1;
                
                // หาตำแหน่งที่จะหยุดการ propagate carry
                while i > 0 && bytes[i] == b'1' {
                    bytes[i] = b'0';
                    i -= 1;
                }
                
                if bytes[i] == b'1' {
                    // ถ้าเจอ '1' ที่ตำแหน่ง i (i=0)
                    bytes[i] = b'0';
                    bytes.insert(0, b'1');
                } else {
                    // เจอ '0' → เปลี่ยนเป็น '1'
                    bytes[i] = b'1';
                }
            }
        }
        
        steps
    }
}