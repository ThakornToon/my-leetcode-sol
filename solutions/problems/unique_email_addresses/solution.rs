use std::collections::HashSet;
impl Solution {
    pub fn num_unique_emails(emails: Vec<String>) -> i32 {
         emails
        .iter()
        .map(|email| {
            let parts: Vec<&str> = email.split('@').collect();
            
            let local = parts[0];
            let domain = parts[1];
            
            // หาตำแหน่งของ +
            let local_clean = match local.find('+') {
                Some(pos) => &local[..pos],
                None => local,
            };
            
            // ลบ . ออก
            let local_final: String = local_clean.chars().filter(|&c| c != '.').collect();
            
            format!("{}@{}", local_final, domain)
        })
        .collect::<HashSet<String>>()
        .len() as i32
    }
}