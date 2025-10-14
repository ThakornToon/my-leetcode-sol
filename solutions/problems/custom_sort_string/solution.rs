impl Solution {
    pub fn custom_sort_string(order: String, s: String) -> String {
        let mut count = [0; 26];
        
        // นับความถี่
        for c in s.chars() {
            count[(c as u8 - b'a') as usize] += 1;
        }
        
        let mut result = String::new();
        
        // เพิ่มตัวอักษรตามลำดับใน order
        for c in order.chars() {
            let idx = (c as u8 - b'a') as usize;
            result.push_str(&c.to_string().repeat(count[idx]));
            count[idx] = 0;
        }
        
        // เพิ่มตัวอักษรที่เหลือ
        for c in b'a'..=b'z' {
            let idx = (c - b'a') as usize;
            if count[idx] > 0 {
                result.push_str(&(c as char).to_string().repeat(count[idx]));
            }
        }
        
        result
    }
}