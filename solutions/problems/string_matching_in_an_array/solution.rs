impl Solution {
    pub fn string_matching(words: Vec<String>) -> Vec<String> {
        let mut words = words;
        words.sort_by_key(|w| w.len());
        let mut result = Vec::new();
        
        for i in 0..words.len() {
            for j in i + 1..words.len() {
                if words[j].contains(&words[i]) {
                    result.push(words[i].clone());
                    break;
                }
            }
        }
        
        result
    }
}