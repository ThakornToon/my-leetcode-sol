impl Solution {
    pub fn num_music_playlists(n: i32, goal: i32, k: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let n = n as usize;
        let goal = goal as usize;
        let k = k as usize;
        
        // dp[i][j] = จำนวนวิธีสร้าง playlist ยาว i โดยใช้ j เพลงที่แตกต่างกัน
        let mut dp = vec![vec![0i64; n + 1]; goal + 1];
        dp[0][0] = 1;  // base case
        
        for i in 1..=goal {
            for j in 1..=n.min(i) { // ลดการคิดกรณีที่เป็นไปไม่ได้
                // เลือกเพลงใหม่: มี n-(j-1) เพลงที่ยังไม่เคยใช้
                dp[i][j] = (dp[i][j] + dp[i-1][j-1] * (n - (j-1)) as i64) % MOD;
                
                // เลือกเพลงเก่า: มี max(0, j-k) เพลงที่เลือกได้
                if j > k {
                    dp[i][j] = (dp[i][j] + dp[i-1][j] * (j - k) as i64) % MOD;
                }
            }
        }
        
        dp[goal][n] as i32
    }
}