impl Solution {
    pub fn license_key_formatting(s: String, k: i32) -> String {
        let mut cleaned: Vec<char> = s.chars()
            .filter(|&c| c != '-')
            .map(|c| c.to_ascii_uppercase())
            .collect();
            
        if cleaned.is_empty() {
            return String::new();
        }
        
        let k = k as usize;
        let len = cleaned.len();
        let mut result = String::with_capacity(len + (len - 1) / k);
        
        let first_group = len % k;
        if first_group != 0 {
            result.extend(cleaned[..first_group].iter());
            if first_group < len {
                result.push('-');
            }
        }
        
        for i in (first_group..len).step_by(k) {
            result.extend(cleaned[i..i+k].iter());
            if i + k < len {
                result.push('-');
            }
        }
        
        result
    }
}