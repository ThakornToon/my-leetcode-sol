use std::collections::HashMap;

impl Solution {
    pub fn len_longest_fib_subseq(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut index = HashMap::new();
        for (i, &val) in arr.iter().enumerate() {
            index.insert(val, i);
        }
        // dp[j][i] ขนาด N*N = ความยาวของลำดับ Fibonacci ที่ลงท้ายด้วย A[j] และ A[i]
        let mut dp = vec![vec![2; n]; n]; // ค่าเริ่มต้นคือความยาว 2
        let mut max_len = 0;
        
        for i in 2..n { // เริ่มดูที่ตัวที่สามเป็นต้นไป
            for j in (1..i).rev() {
                let target = arr[i] - arr[j]; // prev2 = new - prev1
                if target >= arr[j] {
                    break;
                }
                if let Some(&k) = index.get(&target) {
                    dp[j][i] = dp[k][j] + 1; // ต่อลำดับเป็น arr[k], arr[j], arr[i]
                    max_len = max_len.max(dp[j][i]);
                }
            }
        }
        
        if max_len > 2 { max_len } else { 0 }
    }
}