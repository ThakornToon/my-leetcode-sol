impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        if (s.len() == 0) {
            return true;
        }
        let s: Vec<char> = s.chars().collect();
        let mut i = 0;
        for ch in t.chars() {
            if (s[i] == ch) {
                i += 1;
                if (i == s.len()) {
                    return true;
                }
            }
        }

        return i == s.len();  
    }
}