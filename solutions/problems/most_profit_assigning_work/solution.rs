impl Solution {
    pub fn max_profit_assignment(difficulty: Vec<i32>, profit: Vec<i32>, worker: Vec<i32>) -> i32 {
        let mut jobs: Vec<(i32, i32)> = difficulty.into_iter().zip(profit.into_iter()).collect();
        
        // เรียงงานตาม difficulty
        jobs.sort_by_key(|&(d, _)| d);
        
        // เรียง worker
        let mut worker = worker;
        worker.sort();
        
        let mut total = 0;
        let mut max_profit = 0;
        let mut i = 0;
        
        for ability in worker {
            // อัพเดตกำไรสูงสุดสำหรับความสามารถนี้
            while i < jobs.len() && jobs[i].0 <= ability {
                max_profit = max_profit.max(jobs[i].1);
                i += 1;
            }
            total += max_profit;
        }
        
        total
    }
}