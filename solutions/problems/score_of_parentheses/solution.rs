impl Solution {
    pub fn score_of_parentheses(s: String) -> i32 {
        let s = s.as_bytes();
        let mut depth = 0;
        let mut score = 0;
        
        for i in 0..s.len() {
            if s[i] == b'(' {
                depth += 1;
            } else {
                depth -= 1;
                
                // ตรวจสอบว่าเป็นคู่ "()" หรือไม่
                if s[i-1] == b'(' {
                    // เพิ่มคะแนน 2^depth
                    score += 1 << depth;  // 2^depth
                }
            }
        }
        
        return score;
    }
}