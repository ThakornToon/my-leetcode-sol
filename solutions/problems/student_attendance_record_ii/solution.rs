impl Solution {
    pub fn check_record(n: i32) -> i32 {
        const MOD: i32 = 1_000_000_007;
        let n = n as usize;
        
        // dp[j][k] แทนจำนวนวิธีที่ถูกต้องสำหรับวันที่ผ่านมา โดยมีขาดเรียน j ครั้ง และมาสายติดต่อกัน k ครั้ง
        let mut dp = [[0; 3]; 2]; // [absent_count][late_streak]
        dp[0][0] = 1; // เริ่มต้นด้วย 0 absent, 0 late
        
        for _ in 1..=n {
            let mut new_dp = [[0; 3]; 2];
            
            for a in 0..2 { // Absent
                for l in 0..3 { // Late
                    let count = dp[a][l];
                    if count == 0 {
                        continue;
                    }
                    
                    // Present: รีเซ็ต late streak
                    new_dp[a][0] = (new_dp[a][0] + count) % MOD;
                    
                    // Absent: เพิ่ม absent count และรีเซ็ต late streak
                    if a < 1 {
                        new_dp[a + 1][0] = (new_dp[a + 1][0] + count) % MOD;
                    }
                    
                    // Late: เพิ่ม late streak (ถ้าไม่เกิน 2)
                    if l < 2 {
                        new_dp[a][l + 1] = (new_dp[a][l + 1] + count) % MOD;
                    }
                }
            }
            
            dp = new_dp;
        }
        
        // รวมทุกกรณีที่เป็นไปได้
        let mut total = 0;
        for a in 0..2 {
            for l in 0..3 {
                total = (total + dp[a][l]) % MOD;
            }
        }
        total
    }
}