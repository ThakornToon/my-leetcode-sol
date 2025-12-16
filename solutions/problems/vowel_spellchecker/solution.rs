use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn spellchecker(wordlist: Vec<String>, queries: Vec<String>) -> Vec<String> {
        let mut exact_match = HashSet::new();
        let mut case_insensitive = HashMap::new();
        let mut vowel_insensitive = HashMap::new();
        
        // เตรียมข้อมูลจาก wordlist
        for word in &wordlist {
            // Exact match
            exact_match.insert(word.clone());
            
            // Case-insensitive match
            let lower = word.to_lowercase();
            case_insensitive.entry(lower.clone())
                .or_insert_with(|| word.clone());
            
            // Vowel-insensitive match
            let devoweled = Self::devowel(word);
            vowel_insensitive.entry(devoweled)
                .or_insert_with(|| word.clone());
        }
        
        let mut result = Vec::new();
        
        for query in queries {
            // 1. Check exact match
            if exact_match.contains(&query) {
                result.push(query.clone());
                continue;
            }
            
            // 2. Check case-insensitive match
            let lower = query.to_lowercase();
            if let Some(word) = case_insensitive.get(&lower) {
                result.push(word.clone());
                continue;
            }
            
            // 3. Check vowel-insensitive match
            let devoweled = Self::devowel(&query);
            if let Some(word) = vowel_insensitive.get(&devoweled) {
                result.push(word.clone());
                continue;
            }
            
            // 4. Not found
            result.push("".to_string());
        }
        
        result
    }
    
    fn devowel(s: &str) -> String {
        s.to_lowercase()
            .chars()
            .map(|c| match c {
                'a' | 'e' | 'i' | 'o' | 'u' => '*',
                _ => c,
            })
            .collect()
    }
}