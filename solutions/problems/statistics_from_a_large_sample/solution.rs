impl Solution {
    pub fn sample_stats(count: Vec<i32>) -> Vec<f64> {
        let total: i32 = count.iter().sum();
        let target1 = (total - 1) / 2;
        let target2 = total / 2;
        
        let mut sum: i64 = 0;
        let mut min_val = 256;
        let mut max_val = -1;
        let mut mode = 0;
        let mut max_count = 0;
        let mut cnt = 0;
        let mut median1 = -1;
        let mut median2 = -1;
        
        // ลูปเดียวทั้งหมด
        for (i, &c) in count.iter().enumerate() {
            if c == 0 {
                continue;
            }
            
            let i_val = i as i32;
            
            // Min/Max
            if i_val < min_val {
                min_val = i_val;
            }
            if i_val > max_val {
                max_val = i_val;
            }
            
            // Sum
            sum += i_val as i64 * c as i64;
            
            // Mode
            if c > max_count {
                max_count = c;
                mode = i_val;
            }
            
            // Median
            if cnt <= target1 && cnt + c > target1 {
                median1 = i_val;
            }
            if cnt <= target2 && cnt + c > target2 {
                median2 = i_val;
            }
            
            cnt += c;
        }
        
        let mean = sum as f64 / total as f64;
        let median = if total % 2 == 1 {
            median2 as f64
        } else {
            (median1 + median2) as f64 / 2.0
        };
        
        vec![
            min_val as f64,
            max_val as f64,
            mean,
            median,
            mode as f64,
        ]
    }
}