impl Solution {
    pub fn min_flips_mono_incr(s: String) -> i32 {
        let n = s.len();
        if n <= 1 {
            return 0;
        }
        
        let bytes = s.as_bytes();
        
        // dp0 = min flips เพื่อให้ s[0..i] จบด้วย 0
        // dp1 = min flips เพื่อให้ s[0..i] จบด้วย 1
        let mut dp0 = 0;
        let mut dp1 = 0;
        
        for i in 0..n {
            let new_dp0 = dp0 + if bytes[i] == b'1' { 1 } else { 0 }; // 1 -> 0
            let new_dp1 = dp0.min(dp1) + if bytes[i] == b'0' { 1 } else { 0 }; // 0 -> 1
            
            dp0 = new_dp0;
            dp1 = new_dp1;
        }
        
        dp0.min(dp1)
    }
}