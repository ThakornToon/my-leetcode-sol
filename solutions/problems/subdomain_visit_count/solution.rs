use std::collections::HashMap;
impl Solution {
    pub fn subdomain_visits(cpdomains: Vec<String>) -> Vec<String> {
        let mut domain_count = HashMap::new();
        
        for cpdomain in cpdomains {
            let parts: Vec<&str> = cpdomain.splitn(2, ' ').collect();
            let count: i32 = parts[0].parse().unwrap();
            let domain = parts[1];
            
            // Process all subdomains
            let mut current = domain;
            loop {
                *domain_count.entry(current.to_string()).or_insert(0) += count;
                
                if let Some(dot_pos) = current.find('.') {
                    current = &current[dot_pos + 1..];
                } else {
                    break;
                }
            }
        }
        
        domain_count
            .into_iter()
            .map(|(domain, count)| format!("{} {}", count, domain))
            .collect()
    }
}