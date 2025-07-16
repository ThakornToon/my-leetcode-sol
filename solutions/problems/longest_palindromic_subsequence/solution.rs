/*
สร้างตาราง DP ขนาด n x n โดยที่ dp[i][j] แทนความยาวของ LPS ของสตริงย่อยจากตำแหน่ง i ถึง j
ทุกตัวอักษรเป็น palindrome ความยาว 1: dp[i][i] = 1
ถ้าตัวอักษรที่ i และ j เหมือนกัน: dp[i][j] = 2 + dp[i+1][j-1]
ถ้าไม่เหมือน: dp[i][j] = max(dp[i+1][j], dp[i][j-1])
*/
impl Solution {
    pub fn longest_palindrome_subseq(s: String) -> i32 {
        let n = s.len();
        let s = s.as_bytes();
        let mut dp = vec![vec![0; n]; n];
        
        for i in (0..n).rev() {
            dp[i][i] = 1;
            for j in i+1..n {
                if s[i] == s[j] {
                    dp[i][j] = 2 + if i+1 <= j-1 { dp[i+1][j-1] } else { 0 };
                } else {
                    dp[i][j] = dp[i+1][j].max(dp[i][j-1]);
                }
            }
        }
        
        dp[0][n-1]
    }
}