impl Solution {
    pub fn count_substrings(s: String) -> i32 {
        let chars: Vec<char> = s.chars().collect();
        let n = chars.len();
        let mut count = 0;
        
        for i in 0..n {
            // Palindromic substring ความยาวคี่ (center ที่ i)
            let (mut left, mut right) = (i as i32, i as i32);
            while left >= 0 && right < n as i32 && chars[left as usize] == chars[right as usize] {
                count += 1;
                left -= 1;
                right += 1;
            }
            
            // Palindromic substring ความยาวคู่ (center ระหว่าง i และ i+1)
            let (mut left, mut right) = (i as i32, (i + 1) as i32);
            while left >= 0 && right < n as i32 && chars[left as usize] == chars[right as usize] {
                count += 1;
                left -= 1;
                right += 1;
            }
        }
        
        count
    }
}