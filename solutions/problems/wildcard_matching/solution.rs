impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let s_chars: Vec<char> = s.chars().collect();
        let p_chars: Vec<char> = p.chars().collect();
        let m = s_chars.len();
        let n = p_chars.len();

        // ใช้ DP แบบ 1 มิติเพื่อประหยัดพื้นที่
        let mut dp = vec![false; n + 1];
        dp[0] = true;

        // Initialize สำหรับ pattern ที่ขึ้นต้นด้วย *
        for j in 1..=n {
            if p_chars[j-1] == '*' {
                dp[j] = dp[j-1];
            }
        }

        for i in 1..=m {
            let mut prev = dp[0];
            dp[0] = false; // สตริงไม่ว่างแต่ pattern ว่าง -> false
            
            for j in 1..=n {
                let temp = dp[j];
                if p_chars[j-1] == '?' || p_chars[j-1] == s_chars[i-1] {
                    dp[j] = prev;
                } else if p_chars[j-1] == '*' {
                    dp[j] = dp[j] || dp[j-1];
                } else {
                    dp[j] = false;
                }
                prev = temp;
            }
        }

        dp[n]
    }
}