impl Solution {
    pub fn buddy_strings(s: String, goal: String) -> bool {
        let n = s.len();
        if goal.len() != n {
            return false;
        }
        
        let mut shash = [0; 26];
        let mut ghash = [0; 26];
        let mut diff = 0u32;
        
        for (a, b) in s.bytes().zip(goal.bytes()) {
            if a != b {
                diff += 1;
            }
            shash[(a - b'a') as usize] += 1;
            ghash[(b - b'a') as usize] += 1;
        }
        
        let mut dup = false;
        for i in 0..26 {
            if shash[i] != ghash[i] {
                return false;
            }
            if shash[i] >= 2 {
                dup = true;
            }
        }
        
        !(diff > 2 || (diff == 0 && !dup))
    }
}