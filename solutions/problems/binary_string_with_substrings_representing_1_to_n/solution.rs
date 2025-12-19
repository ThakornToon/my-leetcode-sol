impl Solution {
    pub fn query_string(s: String, n: i32) -> bool {
        let n = n as usize;
        let s_bytes = s.as_bytes();
        let len = s.len();
        let mut found = std::collections::HashSet::new();
        
        // สกัดทุก substring จาก s
        for i in 0..len {
            if s_bytes[i] == b'0' {
                continue; // ข้าม leading zero
            }
            
            let mut num = 0;
            for j in i..len {
                num = (num << 1) | ((s_bytes[j] - b'0') as usize);
                
                if num > n {
                    break;
                }
                
                if num >= 1 && num <= n {
                    found.insert(num);
                }
            }
        }
        
        found.len() == n
    }
}