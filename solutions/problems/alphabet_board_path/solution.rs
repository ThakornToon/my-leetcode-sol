impl Solution {
    pub fn alphabet_board_path(target: String) -> String {
        let mut result = String::new();
        let (mut r, mut c) = (0, 0); // ตำแหน่งปัจจุบัน (row, col)
        let mut prev_ch = 'a';
        for ch in target.chars() {
            let idx = ch as u8 - b'a';
            let (tr, tc) = ((idx / 5) as i32, (idx % 5) as i32);
            
            // 1. ซ้าย/ขวา ก่อน (แนวนอน)
            // ยกเว้น: ถ้าจะไป z (แถว 5) ให้ทำแนวนอนให้เสร็จก่อน
            if prev_ch == 'z' {
                // ขึ้น
                while r > tr {
                    result.push('U');
                    r -= 1;
                }

                // ซ้าย/ขวา
                while c > tc {
                    result.push('L');
                    c -= 1;
                }
                while c < tc {
                    result.push('R');
                    c += 1;
                }
            } else {
                // ซ้าย/ขวา
                while c > tc {
                    result.push('L');
                    c -= 1;
                }
                while c < tc {
                    result.push('R');
                    c += 1;
                }
                
                // ขึ้น/ลง
                while r > tr {
                    result.push('U');
                    r -= 1;
                }
                while r < tr {
                    result.push('D');
                    r += 1;
                }
            }
            
            // กดปุ่ม
            result.push('!');
            prev_ch = ch;
        }
        
        result
    }
}