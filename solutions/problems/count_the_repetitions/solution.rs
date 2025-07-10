impl Solution {
    pub fn get_max_repetitions(s1: String, n1: i32, s2: String, n2: i32) -> i32 {
        use std::collections::HashMap;
        let mut memo: HashMap<usize, (i32, i32)> = HashMap::new(); // HashMap เก็บ (s1_count, s2_count) สำหรับแต่ละ index j
        let mut s1_cnt = 0;
        let mut s2_cnt = 0;
        let mut j = 0;
        let s1_chars: Vec<char> = s1.chars().collect();
        let s2_chars: Vec<char> = s2.chars().collect();
        
        while s1_cnt < n1 {
            for &c in &s1_chars {
                if c == s2_chars[j] {
                    j += 1;
                    if j == s2_chars.len() {
                        j = 0;
                        s2_cnt += 1;
                    }
                }
            }
            s1_cnt += 1;
            
            if let Some(&(prev_s1, prev_s2)) = memo.get(&j) {
                let cycle_s1 = s1_cnt - prev_s1;
                let cycle_s2 = s2_cnt - prev_s2;
                
                let remaining_cycles = (n1 - s1_cnt) / cycle_s1;
                s1_cnt += remaining_cycles * cycle_s1;
                s2_cnt += remaining_cycles * cycle_s2;
            } else {
                memo.insert(j, (s1_cnt, s2_cnt));
            }
        }
        
        s2_cnt / n2
    }
}