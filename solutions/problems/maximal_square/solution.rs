impl Solution {
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        let mut dp = vec![vec![0; matrix[0].len() + 1]; matrix.len() + 1];
        let mut side = 0;
        for r in 0..=matrix.len() {
            for c in 0..=matrix[0].len() {
                if r == 0 || c == 0 {
                    dp[r][c] = 0;
                }
                else {
                    dp[r][c] = 0;
                    if matrix[r - 1][c - 1] == '1' {
                        dp[r][c] = dp[r - 1][c].min(dp[r - 1][c - 1].min(dp[r][c - 1])) + 1;
                        if dp[r][c] > side {
                            side = dp[r][c];
                        }
                    }
                }
            }
        }
        return side * side;
    }
}