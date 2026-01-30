impl Solution {
    pub fn min_remove_to_make_valid(s: String) -> String {
        // First pass: remove invalid ')'
        let mut temp = String::new();
        let mut balance = 0;
        
        for c in s.chars() {
            match c {
                '(' => {
                    balance += 1;
                    temp.push(c);
                }
                ')' => {
                    if balance > 0 {
                        balance -= 1;
                        temp.push(c);
                    }
                    // ถ้า balance <= 0 ไม่เพิ่ม
                }
                _ => {
                    temp.push(c);
                }
            }
        }
        
        // Second pass: remove invalid '(' (from right to left)
        let mut result = String::new();
        let mut balance = 0;
        
        // วนจากขวาไปซ้าย
        for c in temp.chars().rev() {
            match c {
                ')' => {
                    balance += 1;
                    result.push(c);
                }
                '(' => {
                    if balance > 0 {
                        balance -= 1;
                        result.push(c);
                    }
                    // ถ้า balance <= 0 ไม่เพิ่ม
                }
                _ => {
                    result.push(c);
                }
            }
        }
        
        // Reverse เพราะสร้างจากขวาไปซ้าย
        result.chars().rev().collect()
    }
}