impl Solution {
    pub fn num_pairs_divisible_by60(time: Vec<i32>) -> i32 {
        let mut count = [0; 60];
        let mut pairs = 0;
        
        for &t in &time {
            let rem = (t % 60) as usize;
            let complement = (60 - rem) % 60;
            
            pairs += count[complement];
            count[rem] += 1;
        }
        
        pairs
    }
}