impl Solution {
    pub fn str_without3a3b(a: i32, b: i32) -> String {
        let mut a = a;
        let mut b = b;
        let mut result = String::new();
        
        while a > 0 || b > 0 {
            if a > b {
                // วาง "aab"
                if a > 0 { result.push('a'); a -= 1; }
                if a > 0 { result.push('a'); a -= 1; }
                if b > 0 { result.push('b'); b -= 1; }
            } else if b > a {
                // วาง "bba"
                if b > 0 { result.push('b'); b -= 1; }
                if b > 0 { result.push('b'); b -= 1; }
                if a > 0 { result.push('a'); a -= 1; }
            } else {
                // เท่ากัน สลับกัน
                if a > 0 { result.push('a'); a -= 1; }
                if b > 0 { result.push('b'); b -= 1; }
            }
        }
        
        result
    }
}