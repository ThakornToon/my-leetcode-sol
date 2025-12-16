impl Solution {
    pub fn is_rational_equal(s: String, t: String) -> bool {
        let d1 = Self::parse_to_double(&s);
        let d2 = Self::parse_to_double(&t);
        (d1 - d2).abs() < 1e-12
    }
    
    fn parse_to_double(s: &str) -> f64 {
        let chars: Vec<char> = s.chars().collect();
        let len = chars.len();
        let mut result = 0.0;
        let mut i = 0;
        
        // Integer part
        while i < len && chars[i] != '.' {
            result = result * 10.0 + (chars[i] as u8 - b'0') as f64;
            i += 1;
        }
        
        // Non-repeating decimal part
        let mut non_repeating_value = 0.0;
        let mut non_repeating_len = 0;
        
        if i < len && chars[i] == '.' {
            i += 1;
            while i < len && chars[i] != '(' {
                non_repeating_value = non_repeating_value * 10.0 + (chars[i] as u8 - b'0') as f64;
                non_repeating_len += 1;
                i += 1;
            }
            result += non_repeating_value / 10f64.powi(non_repeating_len as i32);
        }
        
        // Repeating part
        if i < len && chars[i] == '(' {
            i += 1;
            let mut repeating = 0.0;
            let mut repeat_len = 0;
            
            while i < len && chars[i] != ')' {
                repeating = repeating * 10.0 + (chars[i] as u8 - b'0') as f64;
                repeat_len += 1;
                i += 1;
            }
            
            if repeat_len > 0 {
                let repeating_fraction = repeating / (10f64.powi(repeat_len as i32) - 1.0);
                let scale_factor = 10f64.powi(non_repeating_len as i32);
                result += repeating_fraction / scale_factor;
            }
        }
        
        result
    }
}