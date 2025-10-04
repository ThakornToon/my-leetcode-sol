impl Solution {
    pub fn count_binary_substrings(s: String) -> i32 {
        let bytes = s.as_bytes();
        let n = bytes.len();
        if n <= 1 {
            return 0;
        }
        
        let mut prev = 0;
        let mut curr = 1;
        let mut count = 0;
        
        for i in 1..n {
            if bytes[i] == bytes[i - 1] {
                curr += 1;
            } else {
                prev = curr;
                curr = 1;
            }
            
            if prev >= curr {
                count += 1;
            }
        }
        
        count
    }
}