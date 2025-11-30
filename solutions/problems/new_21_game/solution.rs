/* 
Start with 0 points.
Each turn: draw a random number from 1 to maxPts (equal chance).
Add that number to your score.
Stop when your score reaches k or more.
We want the probability that when you stop, your final score is n or less.
dp[i] = (dp[i-1] + dp[i-2] + ... + dp[i-maxPts]) / maxPts.
*/
impl Solution {
    pub fn new21_game(n: i32, k: i32, max_pts: i32) -> f64 {
        let (n, k, max_pts) = (n as usize, k as usize, max_pts as usize);
        
        if k == 0 {
            return 1.0;
        }
        if n >= k + max_pts - 1 {
            return 1.0;
        }
        
        // คำนวณแค่ถึง k-1
        let mut dp = vec![0.0; k];
        dp[0] = 1.0;
        let mut window_sum = 1.0;
        
        for i in 1..k {
            dp[i] = window_sum / max_pts as f64;
            window_sum += dp[i];
            if i >= max_pts {
                window_sum -= dp[i - max_pts];
            }
        }
        
        // stop between k and n
        let mut result: f64 = 0.0;
        for stop_score in k..=n.min(k + max_pts - 1) {
            result += window_sum / max_pts as f64;
            if stop_score >= max_pts {
                let remove_idx: usize = stop_score - max_pts;
                if remove_idx < k {
                    window_sum -= dp[remove_idx];
                }
            }
        }
        
        result
    }
}