impl Solution {
    pub fn two_edit_words(queries: Vec<String>, dictionary: Vec<String>) -> Vec<String> {
        let mut result = Vec::new();
        
        for q in &queries {
            let q_bytes = q.as_bytes();
            let mut found = false;
            
            for d in &dictionary {
                let d_bytes = d.as_bytes();
                let mut diff = 0;
                
                for i in 0..q_bytes.len() {
                    if q_bytes[i] != d_bytes[i] {
                        diff += 1;
                        if diff > 2 {
                            break;
                        }
                    }
                }
                
                if diff <= 2 {
                    found = true;
                    break;
                }
            }
            
            if found {
                result.push(q.clone());
            }
        }
        
        result
    }
}