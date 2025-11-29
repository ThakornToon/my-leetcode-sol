impl Solution {
    pub fn mask_pii(s: String) -> String {
        if s.contains('@') {
            Self::mask_email(s)
        } else {
            Self::mask_phone(s)
        }
    }
    
    fn mask_email(s: String) -> String {
        let s_lower = s.to_lowercase();
        let parts: Vec<&str> = s_lower.split('@').collect();
        let local_name = parts[0];
        let domain_name = parts[1];
        
        let first_char = local_name.chars().next().unwrap();
        let last_char = local_name.chars().last().unwrap();
        
        format!("{}*****{}@{}", first_char, last_char, domain_name)
    }
    
    fn mask_phone(s: String) -> String {
        let digits: String = s.chars().filter(|c| c.is_ascii_digit()).collect();
        let n = digits.len();
        let last_four = &digits[n-4..];
        
        match n {
            10 => format!("***-***-{}", last_four),
            11 => format!("+*-***-***-{}", last_four),
            12 => format!("+**-***-***-{}", last_four),
            13 => format!("+***-***-***-{}", last_four),
            _ => String::new() // Should not happen according to constraints
        }
    }
}