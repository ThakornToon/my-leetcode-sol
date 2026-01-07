impl Solution {
    pub fn balanced_string_split(s: String) -> i32 {
        let mut balance = 0;
        let mut count = 0;
        
        for c in s.chars() {
            match c {
                'L' => balance += 1,
                'R' => balance -= 1,
                _ => {}  // ไม่น่ามีตัวอื่น
            }
            
            if balance == 0 {
                count += 1;
            }
        }
        
        count
    }
}