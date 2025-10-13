impl Solution {
    pub fn can_transform(start: String, result: String) -> bool {
        let start_chars: Vec<char> = start.chars().collect();
        let end_chars: Vec<char> = result.chars().collect();
        let n = start_chars.len();
        
        let mut i = 0;
        let mut j = 0;
        
        while i < n || j < n {
            // ข้าม 'X' ใน start
            while i < n && start_chars[i] == 'X' {
                i += 1;
            }
            // ข้าม 'X' ใน end
            while j < n && end_chars[j] == 'X' {
                j += 1;
            }
            
            // จบทั้งคู่
            if i == n && j == n {
                return true;
            }
            // ความยาวไม่เท่ากันหลังจากข้าม X
            if i == n || j == n {
                return false;
            }
            
            // ตรวจสอบอักขระไม่ตรงกัน
            if start_chars[i] != end_chars[j] {
                return false;
            }
            
            // ตรวจสอบเงื่อนไขตำแหน่ง
            if start_chars[i] == 'L' && i < j {
                return false;  // L เคลื่อนที่ซ้ายได้เท่านั้น
            }
            if start_chars[i] == 'R' && i > j {
                return false;  // R เคลื่อนที่ขวาได้เท่านั้น
            }
            
            i += 1;
            j += 1;
        }
        
        true
    }
}