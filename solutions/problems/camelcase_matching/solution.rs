impl Solution {
    pub fn camel_match(queries: Vec<String>, pattern: String) -> Vec<bool> {
        let mut answer = Vec::new();
        
        for query in queries {
            answer.push(Self::matches(&query, &pattern));
        }
        
        answer
    }
    
    fn matches(query: &str, pattern: &str) -> bool {
        let query_chars: Vec<char> = query.chars().collect();
        let pattern_chars: Vec<char> = pattern.chars().collect();
        
        let mut i = 0; // pointer for query
        let mut j = 0; // pointer for pattern
        
        while i < query_chars.len() {
            if j < pattern_chars.len() && query_chars[i] == pattern_chars[j] {
                i += 1;
                j += 1;
            } else if query_chars[i].is_lowercase() {
                i += 1;
            } else {
                return false;
            }
        }
        
        j == pattern_chars.len()
    }
}