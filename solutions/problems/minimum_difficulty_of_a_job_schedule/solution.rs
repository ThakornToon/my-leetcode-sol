impl Solution {
    pub fn min_difficulty(job_difficulty: Vec<i32>, d: i32) -> i32 {
        let n = job_difficulty.len();
        let d = d as usize;
        
        if n < d {
            return -1;
        }
        
        // dp[i][j] = min difficulty สำหรับงาน i ตัวแรก แบ่งเป็น j วัน
        let mut dp = vec![vec![i32::MAX; d + 1]; n + 1];
        
        // base case: 1 วัน
        let mut max_so_far = 0;
        for i in 1..=n {
            max_so_far = max_so_far.max(job_difficulty[i - 1]);
            dp[i][1] = max_so_far;
        }
        
        // คำนวณ DP
        for days in 2..=d {
            for i in days..=n {
                let mut max_in_last = 0;
                for j in (days - 1..i).rev() {
                    max_in_last = max_in_last.max(job_difficulty[j]);
                    if dp[j][days - 1] != i32::MAX {
                        dp[i][days] = dp[i][days].min(dp[j][days - 1] + max_in_last);
                    }
                }
            }
        }
        
        dp[n][d]
    }
}