impl Solution {
    fn get_max(slices: &[i32], start: usize, end: usize, n: usize) -> i32 {
        let m = end - start + 1;
        let mut dp = vec![vec![0; n + 1]; m + 1];
        
        for i in 1..=m {
            for j in 1..=n {
                // ไม่เลือกชิ้น i
                dp[i][j] = dp[i - 1][j];
                
                // เลือกชิ้น i (ต้องไม่เลือก i-1)
                if i >= 2 {
                    dp[i][j] = dp[i][j].max(dp[i - 2][j - 1] + slices[start + i - 1]);
                } else if j == 1 {
                    dp[i][j] = dp[i][j].max(slices[start + i - 1]);
                }
            }
        }
        
        dp[m][n]
    }

    pub fn max_size_slices(slices: Vec<i32>) -> i32 {
        if slices.len() == 1 {
            return slices[0];
        }
        
        let n = slices.len() / 3;
        
        // กรณี 1: ไม่เลือกชิ้นสุดท้าย (เลือกได้ถึงชิ้นที่ n-2)
        // กรณี 2: ไม่เลือกชิ้นแรก (เลือกได้ตั้งแต่ชิ้นที่ 1)
        let case1 = Self::get_max(&slices, 0, slices.len() - 2, n);
        let case2 = Self::get_max(&slices, 1, slices.len() - 1, n);
        
        case1.max(case2)
    }

}