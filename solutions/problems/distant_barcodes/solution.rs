use std::collections::HashMap;

impl Solution {
    pub fn rearrange_barcodes(barcodes: Vec<i32>) -> Vec<i32> {
        let n = barcodes.len();
        let mut freq = HashMap::new();
        let mut max_freq = 0;
        let mut max_val = 0;
        
        for &num in &barcodes {
            let count = freq.entry(num).or_insert(0);
            *count += 1;
            
            if *count > max_freq {
                max_freq = *count;
                max_val = num;
            }
        }
        
        if max_freq > (n + 1) / 2 {
            return vec![];
        }
        
        let mut result = vec![0; n];
        let mut idx = 0;
        
        while let Some(count) = freq.get_mut(&max_val) {
            // count เก็บ mutable reference ไปยังค่าใน HashMap
            if *count == 0 {
                break;
            }
            result[idx] = max_val;
            *count -= 1;
            idx += 2;
        }
        
        let keys: Vec<i32> = freq.keys().cloned().collect();
        for num in keys {
            while let Some(count) = freq.get_mut(&num) {
                // count เก็บ mutable reference ไปยังค่าใน HashMap
                if *count == 0 {
                    break;
                }
                if idx >= n {
                    idx = 1;  
                }
                result[idx] = num;
                *count -= 1;
                idx += 2;
            }
        }
        
        result
    }
}