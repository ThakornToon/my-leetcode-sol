impl Solution {
    pub fn repeated_string_match(a: String, b: String) -> i32 {
        let mut repeated = String::new();
        let max_repeat = b.len() / a.len() + 2;
        let mut count = 0;
        
        while count < max_repeat {
            repeated.push_str(&a);
            count += 1;
            
            // ตรวจสอบว่า b เป็น substring ของ repeated หรือไม่
            if repeated.contains(&b) {
                return count as i32;
            }
        }
        
        -1
    }
}