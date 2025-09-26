impl Solution {
    pub fn to_hex(num: i32) -> String {
        if num == 0 {
            return "0".to_string();
        }
        
        let mut n = num as u32;
        let hex_chars: Vec<char> = "0123456789abcdef".chars().collect();
        let mut result = String::new();
        
        while n > 0 {
            let remainder = (n % 16) as usize;
            result.push(hex_chars[remainder]);
            n /= 16;
        }
        
        result.chars().rev().collect()
    }
}