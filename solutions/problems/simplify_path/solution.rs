impl Solution {
    pub fn simplify_path(path: String) -> String {
        let mut stack: Vec<&str> = Vec::new();
    
        for part in path.split('/') {
            match part {
                "" | "." => continue,
                ".." => { stack.pop(); },
                _ => stack.push(part),
            }
        }
        
        if stack.is_empty() {
            return "/".to_string();
        }
        
        let mut result = String::new();
        for part in stack {
            result.push('/');
            result.push_str(part);
        }
        
        result

    }
}