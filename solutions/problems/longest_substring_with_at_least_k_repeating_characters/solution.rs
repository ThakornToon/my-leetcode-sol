impl Solution {
    pub fn longest_substring(s: String, k: i32) -> i32 {
        let s = s.as_bytes();
        Self::helper(s, 0, s.len(), k as usize) as i32
    }

    fn helper(s: &[u8], start: usize, end: usize, k: usize) -> usize {
        if end - start < k {
            return 0;
        }
        
        let mut freq = [0; 26];
        for &c in &s[start..end] {
            freq[(c - b'a') as usize] += 1;
        }
        
        for i in start..end {
            if freq[(s[i] - b'a') as usize] < k {
                let left = Self::helper(s, start, i, k);
                let right = Self::helper(s, i + 1, end, k);
                return left.max(right);
            }
        }
        
        end - start
    }
}