impl Solution {
    pub fn compress(chars: &mut Vec<char>) -> i32 {
        let mut write = 0;
        let mut read = 0;
        let mut count = 0;
        let mut prev = chars[0];
        chars.push('\0');
        
        while read < chars.len() {
            if chars[read] == prev {
                count += 1;
            } else {
                chars[write] = prev;
                write += 1;
                
                if count > 1 {
                    for c in count.to_string().chars() {
                        chars[write] = c;
                        write += 1;
                    }
                }
                
                prev = chars[read];
                count = 1;
            }
            read += 1;
        }
        
        write as i32
    }
}