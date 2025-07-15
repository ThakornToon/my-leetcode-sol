use std::collections::HashMap;

impl Solution {
    pub fn find_rotate_steps(ring: String, key: String) -> i32 {
        let ring: Vec<char> = ring.chars().collect();
        let key: Vec<char> = key.chars().collect();
        let n = ring.len();
        let m = key.len();
        
        let mut char_pos: HashMap<char, Vec<usize>> = HashMap::new();
        for (i, &ch) in ring.iter().enumerate() {
            char_pos.entry(ch).or_insert(Vec::new()).push(i);
        }
        
        let mut dp = vec![vec![i32::MAX; n]; m];
        
        // Initialize for first character
        for &j in char_pos.get(&key[0]).unwrap_or(&Vec::new()) {
            dp[0][j] = j.min(n - j) as i32 + 1;
        }
        
        for i in 1..m {
            for &j in char_pos.get(&key[i]).unwrap_or(&Vec::new()) {
                for &k in char_pos.get(&key[i-1]).unwrap_or(&Vec::new()) {
                    let distance = (j as i32 - k as i32).abs() as usize;
                    let step = distance.min(n - distance) as i32 + 1;
                    dp[i][j] = dp[i][j].min(dp[i-1][k] + step);
                }
            }
        }
        
        *dp.last().unwrap().iter().min().unwrap()
    }
}