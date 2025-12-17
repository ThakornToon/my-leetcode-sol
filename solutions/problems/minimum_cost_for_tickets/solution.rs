impl Solution {
    pub fn mincost_tickets(days: Vec<i32>, costs: Vec<i32>) -> i32 {
        let last_day = *days.last().unwrap() as usize;
        let mut dp = vec![0; last_day + 1];
        let travel_days: std::collections::HashSet<i32> = days.iter().cloned().collect();
        
        for i in 1..=last_day {
            if !travel_days.contains(&(i as i32)) {
                // ไม่ต้องเดินทางวันนี้
                dp[i] = dp[i-1];
            } else {
                // ซื้อตั๋ว 1 วัน
                let mut cost = dp[i-1] + costs[0];
                
                // ซื้อตั๋ว 7 วัน
                cost = cost.min(dp[i.saturating_sub(7)] + costs[1]);
                
                // ซื้อตั๋ว 30 วัน
                cost = cost.min(dp[i.saturating_sub(30)] + costs[2]);
                
                dp[i] = cost;
            }
        }
        
        dp[last_day]
    }
}