impl Solution {
    pub fn closest_target(words: Vec<String>, target: String, start_index: i32) -> i32 {
        let n = words.len();
        let start_index = start_index as usize;
        let mut min_dist = i32::MAX;
        let mut found = false;
        
        for i in 0..n {
            if words[i] == target {
                found = true;
                let forward = (i + n - start_index) % n;
                let backward = (start_index + n - i) % n;
                let dist = forward.min(backward) as i32;
                min_dist = min_dist.min(dist);
            }
        }
        
        if found { min_dist } else { -1 }
    }
}