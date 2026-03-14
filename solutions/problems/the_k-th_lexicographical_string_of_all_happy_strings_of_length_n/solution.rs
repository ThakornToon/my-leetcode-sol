impl Solution {
    pub fn get_happy_string(n: i32, k: i32) -> String {
        let n = n as usize;
        let mut happy: Vec<String> = vec!["a".to_string(), "b".to_string(), "c".to_string()];
        
        for _ in 1..n {
            let mut next = Vec::new();
            for s in happy {
                for c in ['a', 'b', 'c'] {
                    if s.chars().last().unwrap() != c {
                        let mut new_s = s.clone();
                        new_s.push(c);
                        next.push(new_s);
                    }
                }
            }
            happy = next;
        }
        
        if (k as usize) <= happy.len() {
            happy[k as usize - 1].clone()
        } else {
            String::new()
        }
    }
}