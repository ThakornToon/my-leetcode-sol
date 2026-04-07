use std::collections::HashMap;

impl Solution {
    pub fn min_set_size(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let target = n / 2;
        
        // นับความถี่
        let mut freq_map = HashMap::new();
        for &num in &arr {
            *freq_map.entry(num).or_insert(0) += 1;
        }
        
        // รวบรวมความถี่และเรียง
        let mut frequencies: Vec<usize> = freq_map.values().map(|&v| v as usize).collect();
        frequencies.sort_unstable_by(|a, b| b.cmp(a));
        
        let mut sum = 0usize;
        let mut result = 0;
        
        for f in frequencies {
            sum += f;
            result += 1;
            if sum >= target {
                break;
            }
        }
        
        result as i32
    }
}