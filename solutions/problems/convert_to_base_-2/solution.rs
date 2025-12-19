impl Solution {
    pub fn base_neg2(n: i32) -> String {
        if n == 0 {
            return "0".to_string();
        }
        
        let mut result = String::new();
        let mut n = n;
        while n != 0 {
            let mut remainder = n % (-2);
            n = n / (-2);
            
            if remainder < 0 {
                remainder += 2;
                n += 1;
            }
            
            result.push_str(&remainder.to_string());
        }
        
        // เราสร้างจากหลังไปหน้า ต้อง reverse
        result.chars().rev().collect()
    }
}