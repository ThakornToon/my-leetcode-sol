impl Solution {
    pub fn find_replace_string(s: String, indices: Vec<i32>, sources: Vec<String>, targets: Vec<String>) -> String {
        let n = indices.len();
        let mut operations: Vec<(usize, usize)> = Vec::new();
        
        for i in 0..n {
            operations.push((indices[i] as usize, i));
        }
        
        operations.sort();
        
        let mut result = String::new();
        let mut last_pos: usize = 0;
        let s_bytes = s.as_bytes();
        
        for (pos, idx) in operations {
            if pos < last_pos {
                continue;
            }
            
            let source = sources[idx].as_bytes();
            let target = &targets[idx];
            
            result.push_str(&s[last_pos..pos]);
            
            let end_pos = pos + source.len();
            if end_pos <= s_bytes.len() && &s_bytes[pos..end_pos] == source {
                result.push_str(target);
                last_pos = end_pos;
            } else {
                last_pos = pos;
            }
        }
        
        result.push_str(&s[last_pos..]);
        result
    }
}