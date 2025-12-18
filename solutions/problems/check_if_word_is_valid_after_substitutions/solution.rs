impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack = Vec::new();
        
        for c in s.chars() {
            if c == 'c' {
                // ตรวจสอบว่า top 2 ตัวเป็น 'b' และ 'a' หรือไม่
                if stack.len() >= 2 {
                    let b = stack.pop().unwrap();
                    let a = stack.pop().unwrap();
                    
                    if !(a == 'a' && b == 'b') {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        
        stack.is_empty()
    }
}