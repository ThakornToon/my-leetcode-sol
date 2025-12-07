impl Solution {
    pub fn num_special_equiv_groups(words: Vec<String>) -> i32 {
        use std::collections::HashSet;
        
        let mut signatures = HashSet::new();
        
        for s in words {
            let mut odd_chars: Vec<char> = Vec::new();
            let mut even_chars: Vec<char> = Vec::new();
            
            // แยกตัวอักษร
            for (i, c) in s.chars().enumerate() {
                if i % 2 == 0 {
                    even_chars.push(c);
                } else {
                    odd_chars.push(c);
                }
            }
            
            // เรียงลำดับ
            odd_chars.sort();
            even_chars.sort();
            
            // สร้าง signature
            let signature = format!("{:?}#{:?}", odd_chars, even_chars);
            signatures.insert(signature);
        }
        
        signatures.len() as i32
    }
}