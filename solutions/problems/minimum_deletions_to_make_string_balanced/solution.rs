impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let mut b_count = 0;
        let mut deletions = 0;
        
        for c in s.chars() {
            if c == 'a' {
                // ตัวเลือก 1: ลบ 'a' นี้
                // ตัวเลือก 2: ลบ 'b' ก่อนหน้านี้ทั้งหมด
                deletions = (deletions + 1).min(b_count);
            } else { // 'b'
                b_count += 1;
            }
        }
        
        deletions
    }
}