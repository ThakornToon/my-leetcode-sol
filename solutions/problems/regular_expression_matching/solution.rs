impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let s_chars: Vec<char> = s.chars().collect();
        let p_chars: Vec<char> = p.chars().collect();
        let m = s_chars.len();
        let n = p_chars.len();

        // ใช้แค่ 2 แถวแทนตาราง 2D ทั้งหมด
        let mut prev = vec![false; n + 1];
        let mut curr = vec![false; n + 1];
        prev[0] = true;

        // Initialize first row (empty string case)
        for j in 1..=n {
            if p_chars[j-1] == '*' {
                prev[j] = prev[j-2];
            }
        }

        for i in 1..=m {
            curr[0] = false; // สตริงไม่ว่างแต่ pattern ว่าง -> false
            for j in 1..=n {
                if p_chars[j-1] == '.' || p_chars[j-1] == s_chars[i-1] {
                    curr[j] = prev[j-1];
                } else if p_chars[j-1] == '*' {
                    curr[j] = curr[j-2]; // Match 0 times
                    if p_chars[j-2] == '.' || p_chars[j-2] == s_chars[i-1] {
                        curr[j] = curr[j] || prev[j]; // Match 1+ times
                    }
                } else {
                    curr[j] = false;
                }
            }
            std::mem::swap(&mut prev, &mut curr);
        }

        prev[n]
    }
}