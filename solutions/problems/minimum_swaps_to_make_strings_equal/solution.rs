impl Solution {
    pub fn minimum_swap(s1: String, s2: String) -> i32 {
        let mut xy = 0;  // นับ (x,y) pairs
        let mut yx = 0;  // นับ (y,x) pairs
        
        // ใช้ zip เพื่อ iterate ทั้งสองสตริงพร้อมกัน
        for (c1, c2) in s1.chars().zip(s2.chars()) {
            if c1 != c2 {
                if c1 == 'x' {
                    xy += 1;  // pattern: (x,y)
                } else {
                    yx += 1;  // pattern: (y,x)
                }
            }
        }
        
        // ตรวจสอบความเป็นไปได้
        if (xy + yx) % 2 == 1 {
            return -1;
        }
        
        // คำนวนจำนวนการสลับ
        // xy/2 + yx/2 + (xy%2)*2
        (xy / 2) + (yx / 2) + (xy % 2) * 2
    }
}