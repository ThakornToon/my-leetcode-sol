impl Solution {
    pub fn ship_within_days(weights: Vec<i32>, days: i32) -> i32 {
        let mut min_capacity: i32 = *weights.iter().max().unwrap();
        let mut max_capacity: i32 = weights.iter().sum();
        
        while min_capacity < max_capacity {
            let mid = min_capacity + (max_capacity - min_capacity) / 2;
            let mut current_load = 0;
            let mut required_days = 1;
            
            for &w in &weights {
                if current_load + w > mid {
                    required_days += 1;
                    current_load = w;
                } else {
                    current_load += w;
                }
            }
            
            if required_days <= days {
                max_capacity = mid;
            } else {
                min_capacity = mid + 1;
            }
        }
        
        max_capacity
    }
}