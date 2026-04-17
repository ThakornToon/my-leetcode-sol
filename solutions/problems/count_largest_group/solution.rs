impl Solution {
    fn digit_sum(mut num: i32) -> i32 {
        let mut sum = 0;
        while num > 0 {
            sum += num % 10;
            num /= 10;
        }
        sum
    }
    
    pub fn count_largest_group(n: i32) -> i32 {
        use std::collections::HashMap;
        
        let mut freq = HashMap::new();
        let mut max_freq = 0;
        
        for i in 1..=n {
            let sum = Self::digit_sum(i);
            let count = freq.entry(sum).or_insert(0);
            *count += 1;
            max_freq = max_freq.max(*count);
        }
        
        freq.values()
            .filter(|&&f| f == max_freq)
            .count() as i32
    }
}