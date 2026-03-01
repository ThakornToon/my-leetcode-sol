impl Solution {
    pub fn min_partitions(n: String) -> i32 {
        let mut max_digit = 0;
        
        for c in n.chars() {
            // แปลง char เป็น digit
            let digit = c.to_digit(10).unwrap() as i32;
            max_digit = max_digit.max(digit);
            
            // optimize: ถ้าเจอ 9 แล้วหยุด
            if max_digit == 9 {
                return 9;
            }
        }
        
        max_digit
    }
}