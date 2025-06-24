impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let len = s.len();
        if len == 0 {
            return String::new();
        }

        // สร้าง DP table โดยใช้ Vec ของ Vec
        let mut dp = vec![vec![2; len]; len]; // 2 แทน "ยังไม่คำนวณ"
        
        let mut max_len = 1;
        let mut start_idx = 0;
        let bytes = s.as_bytes();

        // ฟังก์ชันตรวจสอบพาลินโดรมแบบ recursive
        fn check_palin(bytes: &[u8], dp: &mut Vec<Vec<i32>>, start: usize, end: usize) -> i32 {
            if dp[start][end] != 2 {
                return dp[start][end];
            }

            if start >= end {
                dp[start][end] = 1;
            } else if bytes[start] != bytes[end] {
                dp[start][end] = 0;
            } else {
                dp[start][end] = check_palin(bytes, dp, start + 1, end - 1);
            }
            dp[start][end]
        }

        // ตรวจสอบทุกสตริงย่อย
        for i in 0..len {
            for j in i..len {
                if check_palin(&bytes, &mut dp, i, j) == 1 && (j - i + 1) > max_len {
                    max_len = j - i + 1;
                    start_idx = i;
                }
            }
        }

        // สร้างสตริงผลลัพธ์
        s[start_idx..start_idx + max_len].to_string()
    }
}