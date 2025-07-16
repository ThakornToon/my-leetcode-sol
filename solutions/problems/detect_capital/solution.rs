impl Solution {
    pub fn detect_capital_use(word: String) -> bool {
        let mut count = 0;
        for c in word.chars() {
            if c.is_uppercase() {
                count += 1;
            }
        }
        
        count == word.len() || 
        count == 0 || 
        (count == 1 && word.chars().next().unwrap().is_uppercase())
    }
}