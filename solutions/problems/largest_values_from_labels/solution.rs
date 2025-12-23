use std::collections::HashMap;
impl Solution {
    pub fn largest_vals_from_labels(values: Vec<i32>, labels: Vec<i32>, num_wanted: i32, use_limit: i32) -> i32 {
        let n = values.len();
        let mut items: Vec<(i32, i32)> = values.into_iter().zip(labels.into_iter()).collect();
        
        // เรียงจากมากไปน้อยตาม value
        items.sort_by(|a, b| b.0.cmp(&a.0));
        
        let mut label_count = HashMap::new();
        let mut sum = 0;
        let mut selected = 0;
        
        for (value, label) in items {
            if selected >= num_wanted {
                break;
            }
            
            let count = label_count.entry(label).or_insert(0);
            if *count < use_limit {
                sum += value;
                *count += 1;
                selected += 1;
            }
        }
        
        sum
    }
}