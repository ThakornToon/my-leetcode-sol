impl Solution {
    pub fn binary_gap(n: i32) -> i32 {
        let mut max_gap = 0;
        let mut last_pos: Option<i32> = None;
        let mut pos = 0;
        let mut num = n;
        
        while num > 0 {
            if num & 1 == 1 {
                if let Some(last) = last_pos {
                    max_gap = max_gap.max(pos - last);
                }
                last_pos = Some(pos);
            }
            pos += 1;
            num >>= 1;
        }
        
        max_gap
    }
}