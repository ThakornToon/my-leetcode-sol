impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut m = 0;
        let mut last_pos = [0; 128];
        let mut start = 0;
        let l = 0;
        for (end, c) in s.chars().enumerate(){
            start = start.max(last_pos[c as usize]);
            m = m.max(end-start+1);
            last_pos[c as usize] = end+1;
        }
        return m as i32;
    }
}