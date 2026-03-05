impl Solution {
    pub fn min_operations(s: String) -> i32 {
        let n = s.len();
        let s = s.as_bytes();
        let mut count1 = 0;  // pattern: 0101...
        let mut count2 = 0;  // pattern: 1010...
        
        for i in 0..n {
            if i % 2 == 0 {
                // ตำแหน่งคู่
                if s[i] != b'0' { count1 += 1; }
                if s[i] != b'1' { count2 += 1; }
            } else {
                // ตำแหน่งคี่
                if s[i] != b'1' { count1 += 1; }
                if s[i] != b'0' { count2 += 1; }
            }
        }
        
        count1.min(count2)
    }
}