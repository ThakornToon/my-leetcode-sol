impl Solution {
    pub fn nearest_palindromic(n: String) -> String {
        let num: i64 = n.parse().unwrap();
        let len = n.len();
        
        if len == 1 {
            return (num - 1).to_string();
        }
        
        let mut candidates = vec![
            10_i64.pow((len - 1) as u32) - 1,  // 999...9
            10_i64.pow(len as u32) + 1         // 100...001
        ];
        
        let prefix = &n[..(len + 1)/2];
        let half: i64 = prefix.parse().unwrap();
        
        for i in half-1..=half+1 {
            let left = i.to_string();
            let mirrored = if len % 2 == 0 {
                left.clone() + &left.chars().rev().collect::<String>()
            } else {
                left.clone() + &left[..left.len()-1].chars().rev().collect::<String>()
            };
            candidates.push(mirrored.parse().unwrap());
        }
        
        let mut min_diff = i64::MAX;
        let mut result = 0;
        
        for cand in candidates {
            if cand == num { continue; }
            
            let diff = (cand - num).abs();
            if diff < min_diff || (diff == min_diff && cand < result) {
                min_diff = diff;
                result = cand;
            }
        }
        
        result.to_string()
    }
}