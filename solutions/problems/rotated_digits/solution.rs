impl Solution {
    pub fn rotated_digits(n: i32) -> i32 {
        let valid_digits = [0, 1, 2, 5, 6, 8, 9];
        let mut count = 0;
        
        Self::generate_numbers(0, false, n as i64, &valid_digits, &mut count);
        count
    }
    
    fn generate_numbers(
        current: i64, 
        has_good_digit: bool, 
        max_n: i64, 
        valid_digits: &[i32], 
        count: &mut i32
    ) {
        if current > max_n {
            return;
        }
        
        if has_good_digit && current > 0 {
            *count += 1;
        }
        
        for &digit in valid_digits {
            // หลีกเลี่ยง leading zero
            if current == 0 && digit == 0 {
                continue;
            }
            
            let next = current * 10 + digit as i64;
            let new_has_good_digit = has_good_digit || 
                                   digit == 2 || digit == 5 || digit == 6 || digit == 9;
            
            Self::generate_numbers(next, new_has_good_digit, max_n, valid_digits, count);
        }
    }
}