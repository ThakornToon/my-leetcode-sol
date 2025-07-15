impl Solution {
    pub fn convert_to_base7(num: i32) -> String {
        if num == 0 {
            return "0".to_string();
        }
        
        let mut num = num;
        let is_negative = num < 0;
        num = num.abs();
        let mut result = String::new();
        
        while num > 0 {
            result.push_str(&(num % 7).to_string());
            num /= 7;
        }
        
        if is_negative {
            result.push('-');
        }
        
        result.chars().rev().collect()
    }
}