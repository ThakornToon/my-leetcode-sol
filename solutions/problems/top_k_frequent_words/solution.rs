use std::collections::HashMap;
impl Solution {
    pub fn top_k_frequent(words: Vec<String>, k: i32) -> Vec<String> {
        let k = k as usize;
        
        // Count frequencies
        let mut freq = HashMap::new();
        for word in words {
            *freq.entry(word).or_insert(0) += 1;
        }
        
        // Convert to vector for sorting
        let mut word_freq: Vec<(String, i32)> = freq.into_iter().collect();
        
        // Sort by frequency (descending) and then by word (ascending)
        word_freq.sort_by(|a, b| {
            if a.1 != b.1 {
                b.1.cmp(&a.1) // Higher frequency first
            } else {
                a.0.cmp(&b.0) // Lexicographical order
            }
        });

        word_freq.into_iter()
                 .take(k)
                 .map(|(word, _)| word)
                 .collect()
    }
}