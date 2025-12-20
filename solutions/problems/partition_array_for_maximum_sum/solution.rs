impl Solution {
    pub fn max_sum_after_partitioning(arr: Vec<i32>, k: i32) -> i32 {
        // dp[i] เก็บค่ามากสุดของลำดับยาว 0 ถึง 
        let n = arr.len();
        let k = k as usize;
        let mut dp = vec![0; n + 1];
        
        for i in 1..=n {
            let mut current_max = 0;
            
            // ลองทุกความยาวของส่วนสุดท้าย (1..=k)
            for j in 1..=k {
                if j > i {
                    break;
                }
                
                // หาค่าสูงสุดในส่วนสุดท้าย
                current_max = current_max.max(arr[i - j]);
                
                // อัพเดต dp
                dp[i] = dp[i].max(dp[i - j] + current_max * (j as i32));
            }
        }
        
        dp[n]
    }
}