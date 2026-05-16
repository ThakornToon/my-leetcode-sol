impl Solution {
    pub fn sum_odd_length_subarrays(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut total = 0;
        
        for start in 0..n {
            for len in (1..=n - start).step_by(2) {
                let sum: i32 = arr[start..start + len].iter().sum();
                total += sum;
            }
        }
        
        total
    }
}