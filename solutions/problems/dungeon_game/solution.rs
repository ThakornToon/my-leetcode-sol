impl Solution {
    pub fn calculate_minimum_hp(dungeon: Vec<Vec<i32>>) -> i32 {
        let row = dungeon.len();
        let col = dungeon[0].len();
        let mut dp = vec![i32::MAX - 1000; col + 1];
        dp[col] = 1;
        for r in (0..row).rev() {
            for c in (0..col).rev() {
                dp[c] = (dp[c] - dungeon[r][c]).min(dp[c + 1] - dungeon[r][c]);
                if dp[c] <= 0 {
                    dp[c] = 1;
                }
            }
            dp[col] = dp[col - 1]; 
        }
        return dp[0];
    }
}