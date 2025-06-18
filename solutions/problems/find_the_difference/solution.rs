impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        let mut res: u8 = 0;
        
        // XOR ทุกไบต์ใน s
        for c in s.bytes() {
            res ^= c;
        }
        
        // XOR ทุกไบต์ใน t
        for c in t.bytes() {
            res ^= c;
        }
        
        // แปลงกลับเป็น char
        res as char
    }
}