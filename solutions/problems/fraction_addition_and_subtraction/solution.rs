impl Solution {
    pub fn fraction_addition(expression: String) -> String {
        let mut numerator: i32 = 0;
        let mut denominator: i32 = 1;
        let mut chars: Vec<char> = expression.chars().collect();
        let mut i = 0;
        let n = chars.len();
        
        while i < n {
            // อ่านเครื่องหมาย
            let mut sign = 1;
            if chars[i] == '+' || chars[i] == '-' {
                if chars[i] == '-' {
                    sign = -1;
                }
                i += 1;
            }
            
            // อ่านตัวเศษ
            let mut num = 0;
            while i < n && chars[i].is_ascii_digit() {
                num = num * 10 + chars[i].to_digit(10).unwrap() as i32;
                i += 1;
            }
            num *= sign;
            
            // ข้ามเครื่องหมาย /
            i += 1;
            
            // อ่านตัวส่วน
            let mut den = 0;
            while i < n && chars[i].is_ascii_digit() {
                den = den * 10 + chars[i].to_digit(10).unwrap() as i32;
                i += 1;
            }
            
            // บวกเศษส่วน
            numerator = numerator * den + num * denominator;
            denominator *= den;
            
            // ทำให้เป็นเศษส่วนอย่างต่ำ
            let gcd_val = Self::gcd(numerator.abs(), denominator);
            numerator /= gcd_val;
            denominator /= gcd_val;
        }
        
        format!("{}/{}", numerator, denominator)
    }
    
    fn gcd(a: i32, b: i32) -> i32 {
        if b == 0 { a } else { Self::gcd(b, a % b) }
    }
}