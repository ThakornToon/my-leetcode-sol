use std::collections::HashMap;

impl Solution {
    pub fn longest_balanced(s: String) -> i32 {
        let chars: Vec<char> = s.chars().collect();
        let n = chars.len();
        let mut max_len = 0;
        
        for i in 0..n {
            let mut freq = vec![0; 26];
            
            for j in i..n {
                let idx = chars[j] as usize - 'a' as usize;
                freq[idx] += 1;
                
                // หาความถี่ของตัวแรกที่เจอ
                let mut target = -1;
                let mut balanced = true;
                
                for c in 0..26 {
                    if freq[c] > 0 {
                        if target == -1 {
                            target = freq[c];
                        } else if freq[c] != target {
                            balanced = false;
                            break;
                        }
                    }
                }
                
                if balanced {
                    max_len = max_len.max((j - i + 1) as i32);
                }
            }
        }
        
        max_len
    }
}