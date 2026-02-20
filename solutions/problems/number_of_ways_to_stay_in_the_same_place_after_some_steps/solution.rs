impl Solution {
    const MOD: i64 = 1_000_000_007;
    
    pub fn num_ways(steps: i32, arr_len: i32) -> i32 {
        let steps = steps as usize;
        let arr_len = arr_len as usize;
        
        // ลดขอบเขต: ไม่ต้องพิจารณาตำแหน่งที่ > steps/2
        let max_pos = (arr_len - 1).min(steps / 2);
        
        let mut dp = vec![0i64; max_pos + 1];
        let mut next = vec![0i64; max_pos + 1];
        
        dp[0] = 1;
        
        for _ in 1..=steps {
            for pos in 0..=max_pos {
                let mut ways = dp[pos];  // อยู่ที่เดิม
                
                if pos > 0 {
                    ways = (ways + dp[pos - 1]) % Self::MOD;  // ซ้าย
                }
                
                if pos < max_pos {
                    ways = (ways + dp[pos + 1]) % Self::MOD;  // ขวา
                }
                
                next[pos] = ways;
            }
            
            std::mem::swap(&mut dp, &mut next);
            next.fill(0);
        }
        
        dp[0] as i32
    }
}