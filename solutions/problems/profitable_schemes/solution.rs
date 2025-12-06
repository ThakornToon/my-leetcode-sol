impl Solution {
    pub fn profitable_schemes(n: i32, min_profit: i32, group: Vec<i32>, profit: Vec<i32>) -> i32 {
        const MOD: i32 = 1_000_000_007;
        let n = n as usize;
        let min_profit = min_profit as usize;
        let m = group.len();
        
        // dp[j][k] พิจารณาปัจจุบันใช้ไป j คน ได้กำไร k = จำนวนวิธี
        let mut dp = vec![vec![0; min_profit + 1]; n + 1];
        // Base case ใช้ไป 0 คน ได้กำไร 0 มีหนึ่งวิธี
        dp[0][0] = 1;
        
        for i in 0..m { // พิจารณาทีละแผน
            let g = group[i] as usize;
            let p = profit[i] as usize;
            
            // Iterate backwards
            for j in (g..=n).rev() {
                for k in (0..=min_profit).rev() {
                    // ไม่เลือกแผนนี้ก็ไม่ต้องทำอะไร curr[j][k] = prev[j][k];

                    // เลือกแผนนี้
                    let new_profit = (k + p).min(min_profit);
                    dp[j][new_profit] = (dp[j][new_profit] + dp[j - g][k]) % MOD;
                }
            }
        }
        
        let mut ans = 0;
        for j in 0..=n {
            ans = (ans + dp[j][min_profit]) % MOD;
        }
        ans
    }
}