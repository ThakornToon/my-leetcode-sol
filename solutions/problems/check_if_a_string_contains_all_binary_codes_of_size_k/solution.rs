impl Solution {
    pub fn has_all_codes(s: String, k: i32) -> bool {
        let k = k as usize;
        let n = s.len();
        let total = 1 << k;
        
        if n < total + k - 1 {
            return false;
        }
        
        let mut seen = vec![false; total];
        let chars: Vec<u8> = s.bytes().collect();
        
        // คำนวณ hash สำหรับ k ตัวแรก
        let mut hash = 0;
        for i in 0..k {
            hash = (hash << 1) | ((chars[i] - b'0') as usize);
        }
        seen[hash] = true;
        let mut count = 1;
        let mask = total - 1;
        
        // ใช้ sliding window
        for i in k..n {
            hash = ((hash << 1) & mask) | ((chars[i] - b'0') as usize);
            if !seen[hash] {
                seen[hash] = true;
                count += 1;
            }
        }
        
        count == total
    }
}