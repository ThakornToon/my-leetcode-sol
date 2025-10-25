impl Solution {
    pub fn num_friend_requests(ages: Vec<i32>) -> i32 {
        let mut freq = vec![0; 121];
        for &age in &ages {
            freq[age as usize] += 1;
        }
        
        let mut requests = 0;
        
        for age_a in 15..=120 {
            if freq[age_a] == 0 {
                continue;
            }
            
            let lower_bound = age_a as i32 / 2 + 7;
            
            // นับจำนวนคนที่อายุอยู่ใน (lower_bound, age_a]
            let mut count = 0;
            for age_b in (lower_bound + 1)..=age_a as i32 {
                if age_b <= 120 {
                    count += freq[age_b as usize];
                }
            }
            
            requests += freq[age_a] * count;
            
            // ลบตัวเองถ้าอยู่ใน range
            if age_a as i32 > lower_bound {
                requests -= freq[age_a];
            }
        }
        
        requests
    }
}