use std::collections::HashMap;

impl Solution {
    pub fn job_scheduling(start_time: Vec<i32>, end_time: Vec<i32>, profit: Vec<i32>) -> i32 {
        let n = start_time.len();
        
        // สร้างและเรียงงาน
        let mut jobs: Vec<(i32, i32, i32)> = (0..n)
            .map(|i| (start_time[i], end_time[i], profit[i]))
            .collect();
        
        jobs.sort_by_key(|&(_, e, _)| e);
        
        // สร้าง dp และ end_times สำหรับ binary search
        let mut dp = vec![0; n + 1];
        // เรียง end แล้ว
        let end_times: Vec<i32> = jobs.iter().map(|&(_, e, _)| e).collect();
        
        for i in 1..=n {
            let (start, _, profit) = jobs[i - 1];
            
            // Binary search หางานที่สิ้นสุดก่อน start
            let j = match end_times[0..i - 1].binary_search(&start) {
                Ok(pos) => pos + 1,      // พบงานที่สิ้นสุดพอดี
                Err(pos) => pos,         // ไม่พบ, pos คือ index ที่ควรแทรก
            };
            
            // dp[i] = max(ไม่ทำงาน i, ทำงาน i)
            dp[i] = dp[i - 1].max(profit + dp[j]);
        }
        
        dp[n]
    }
}