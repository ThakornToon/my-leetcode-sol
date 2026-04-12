use std::cmp::max;

impl Solution {
    pub fn max_jumps(arr: Vec<i32>, d: i32) -> i32 {
        let n = arr.len();
        let d = d as usize;
        let mut dp = vec![1; n];
        
        let mut indices: Vec<usize> = (0..n).collect();
        indices.sort_by_key(|&i| arr[i]);
        
        for &i in &indices {
            // กระโดดไปทางขวา
            for j in i + 1..=i + d {
                if j >= n { break; }
                if arr[j] >= arr[i] { break; }
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            
            // กระโดดไปทางซ้าย
            for j in (i.saturating_sub(d)..i).rev() {
                if arr[j] >= arr[i] { break; }
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        
        *dp.iter().max().unwrap()
    }
}