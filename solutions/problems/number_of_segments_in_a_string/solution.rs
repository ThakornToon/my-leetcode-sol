impl Solution {
    pub fn count_segments(s: String) -> i32 {
        let mut count = 0;
        let mut in_segment = false;
        
        for c in s.chars() {
            if c != ' ' && !in_segment {
                count += 1;
                in_segment = true;
            } else if c == ' ' {
                in_segment = false;
            }
        }
        
        count
    }
}