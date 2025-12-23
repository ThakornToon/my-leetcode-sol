impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let m = text1.len();
        let n = text2.len();
        let text1_chars: Vec<char> = text1.chars().collect();
        let text2_chars: Vec<char> = text2.chars().collect();
        
        // dp[i][j] เมื่อพิจารณา str1 i ตัวแรก และ str2 j ตัวแรก จับคู่กันได้ความยาวมากสุดเท่าไร
        let mut dp = vec![vec![0; n + 1]; m + 1];
        
        // กรอกตาราง DP
        for i in 1..=m {
            for j in 1..=n {
                if text1_chars[i - 1] == text2_chars[j - 1] {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i - 1][j].max(dp[i][j - 1]);
                }
            }
        }
        
        dp[m][n]
    }
}