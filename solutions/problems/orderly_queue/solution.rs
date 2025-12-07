impl Solution {
    pub fn orderly_queue(s: String, k: i32) -> String {
        let mut chars: Vec<char> = s.chars().collect();
        
        if k == 1 {
            // หา rotation ที่น้อยที่สุด
            let mut ans: String = s.clone();
            let doubled: String = s.clone() + &s;
            
            for i in 1..chars.len() {
                let candidate: &str = &doubled[i..i + chars.len()];
                if candidate < &ans {
                    ans = candidate.to_string();
                }
            }
            ans
        } else {
            // k ≥ 2: เรียงลำดับ
            chars.sort();
            chars.into_iter().collect()
        }
    }
}