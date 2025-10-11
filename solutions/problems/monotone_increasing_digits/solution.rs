impl Solution {
    pub fn monotone_increasing_digits(n: i32) -> i32 {
        let mut digits: Vec<u8> = n.to_string()
            .chars()
            .map(|c| c.to_digit(10).unwrap() as u8)
            .collect();
        
        let len = digits.len();
        let mut marker = len;
        
        for i in (1..len).rev() {
            if digits[i] < digits[i - 1] {
                marker = i;
                digits[i - 1] -= 1;
            }
        }
        
        for i in marker..len {
            digits[i] = 9;
        }
        
        digits.iter()
            .fold(0, |acc, &x| acc * 10 + x as i32)
    }
}