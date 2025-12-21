impl Solution {
    pub fn remove_duplicates(s: String) -> String {
        let mut result = String::new();
        
        for c in s.chars() {
            if result.ends_with(c) {
                result.pop();
            } else {
                result.push(c);
            }
        }
        
        result
    }
}