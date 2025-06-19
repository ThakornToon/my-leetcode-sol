impl Solution {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        let s_bytes = s.as_bytes();
        let p_bytes = p.as_bytes();
        let mut result = Vec::new();
        
        if s_bytes.len() < p_bytes.len() {
            return result;
        }
        
        let mut p_count = [0; 26]; // array ขนาดคงที่
        let mut s_count = [0; 26]; // array ขนาดคงที่
        
        // นับความถี่ของตัวอักษรใน p
        for &c in p_bytes {
            p_count[(c - b'a') as usize] += 1;
        }
        
        // เริ่ม sliding window
        for i in 0..s_bytes.len() {
            // เพิ่มตัวอักษรปัจจุบันใน window
            s_count[(s_bytes[i] - b'a') as usize] += 1;
            
            // ถ้า window มีขนาดใหญ่เกิน ให้ลบตัวอักษรที่ออกจาก window
            if i >= p_bytes.len() {
                s_count[(s_bytes[i - p_bytes.len()] - b'a') as usize] -= 1;
            }
            
/*
Rust อนุญาตให้เปรียบเทียบ array ที่มีขนาดเดียวกันได้โดยตรง
การเปรียบเทียบจะตรวจสอบว่าแต่ละ element ใน array เท่ากันทุกตำแหน่ง
*/
            if s_count == p_count {
                result.push((i as i32) - (p_bytes.len() as i32) + 1);
            }
        }
        
        result
    }
}