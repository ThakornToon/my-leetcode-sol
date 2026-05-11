impl Solution {
    pub fn num_splits(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        
        let mut right_freq = [0; 26];
        let mut left_freq = [0; 26];
        
        let mut right_distinct = 0;
        let mut left_distinct = 0;
        
        // นับความถี่ทางขวาทั้งหมด
        for &c in s {
            let idx = (c - b'a') as usize;
            if right_freq[idx] == 0 {
                right_distinct += 1;
            }
            right_freq[idx] += 1;
        }
        
        let mut count = 0;
        
        // เลื่อน split ไปทีละตำแหน่ง
        for i in 0..n - 1 {
            let idx = (s[i] - b'a') as usize;
            
            // ย้ายจากขวาไปซ้าย
            left_freq[idx] += 1;
            if left_freq[idx] == 1 {
                left_distinct += 1;
            }
            
            right_freq[idx] -= 1;
            if right_freq[idx] == 0 {
                right_distinct -= 1;
            }
            
            if left_distinct == right_distinct {
                count += 1;
            }
        }
        
        count
    }
}