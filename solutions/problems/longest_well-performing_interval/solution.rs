impl Solution {
    pub fn longest_wpi(hours: Vec<i32>) -> i32 {
        let n = hours.len();
        let mut prefix = vec![0; n + 1];
        
        // คำนวณ prefix sum
        for i in 0..n {
            prefix[i + 1] = prefix[i] + if hours[i] > 8 { 1 } else { -1 };
        }
        
        let mut first_seen = std::collections::HashMap::new();
        let mut max_len = 0;
        
        for i in 0..=n {
            if prefix[i] > 0 {
                // ถ้า prefix[i] > 0, ช่วง [0, i) เป็น valid
                max_len = max_len.max(i as i32);
            } else {
                // หา j ที่ prefix[j] = prefix[i] - 1
                let target = prefix[i] - 1;
                if let Some(&j) = first_seen.get(&target) {
                    max_len = max_len.max((i as i32) - j);
                }
            }
            
            // เก็บ index แรกของ prefix[i] เท่านั้น
            first_seen.entry(prefix[i]).or_insert(i as i32);
        }
        
        max_len
    }
}