impl Solution {
    pub fn max_score(card_points: Vec<i32>, k: i32) -> i32 {
        let n = card_points.len();
        let k = k as usize;
        let mut prefix = vec![0; n + 1];
        for i in 0..n {
            prefix[i + 1] = prefix[i] + card_points[i];
        }
        
        let mut max_sum = 0;
        for i in 0..=k {
            let front_sum = prefix[i];
            let back_sum = prefix[n] - prefix[n - (k - i)];
            max_sum = max_sum.max(front_sum + back_sum);
        }
        
        max_sum
    }
}