use std::collections::HashMap;

impl Solution {
    pub fn k_similarity(s1: String, s2: String) -> i32 {
        let mut memo: HashMap<(Vec<char>, usize), i32> = HashMap::new();
        let mut s1_chars: Vec<char> = s1.chars().collect();
        let s2_chars: Vec<char> = s2.chars().collect();
        
        Self::backtrack_memo(&mut s1_chars, &s2_chars, 0, &mut memo)
    }
    
    fn backtrack_memo(
        s1: &mut Vec<char>,
        s2: &Vec<char>,
        pos: usize,
        memo: &mut HashMap<(Vec<char>, usize), i32>
    ) -> i32 {
        if s1 == s2 {
            return 0;
        }
        
        let key = (s1.clone(), pos);
        if let Some(&val) = memo.get(&key) {
            return val;
        }
        
        let n = s1.len();
        let mut current_pos = pos;
        
        // ข้ามตำแหน่งที่ตรงกัน
        while current_pos < n && s1[current_pos] == s2[current_pos] {
            current_pos += 1;
        }
        
        let mut min_swaps = i32::MAX;
        
        for i in current_pos + 1..n {
            if s1[i] == s2[current_pos] && s1[i] != s2[i] {
                s1.swap(current_pos, i);
                
                let next_swaps = 1 + Self::backtrack_memo(s1, s2, current_pos + 1, memo);
                min_swaps = min_swaps.min(next_swaps);
                
                s1.swap(current_pos, i);  // backtrack
                
                // Greedy optimization
                if s1[current_pos] == s2[i] {
                    break;
                }
            }
        }
        
        let result = if min_swaps == i32::MAX { 0 } else { min_swaps };
        memo.insert(key, result);
        result
    }
}