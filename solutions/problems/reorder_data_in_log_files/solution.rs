impl Solution {
    pub fn reorder_log_files(logs: Vec<String>) -> Vec<String> {
        let mut letter_logs: Vec<String> = Vec::new();
        let mut digit_logs: Vec<String> = Vec::new();
        
        // แยก logs
        for log in logs {
            let space_pos = log.find(' ').unwrap();
            let first_char_after_space = log.chars().nth(space_pos + 1).unwrap();
            
            if first_char_after_space.is_digit(10) {
                digit_logs.push(log);
            } else {
                letter_logs.push(log);
            }
        }
        
        // Sort letter logs
        letter_logs.sort_by(|a, b| {
            let space_a = a.find(' ').unwrap();
            let space_b = b.find(' ').unwrap();
            
            let content_a = &a[space_a + 1..];
            let content_b = &b[space_b + 1..];
            
            // เปรียบเทียบ content
            match content_a.cmp(content_b) {
                std::cmp::Ordering::Equal => {
                    // ถ้า content เท่ากัน ให้เปรียบเทียบ identifier
                    let id_a = &a[..space_a];
                    let id_b = &b[..space_b];
                    id_a.cmp(id_b)
                }
                other => other,
            }
        });
        
        // รวมผลลัพธ์
        let mut result = letter_logs;
        result.extend(digit_logs);
        result
    }
}