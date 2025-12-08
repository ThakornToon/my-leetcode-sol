impl Solution {
    pub fn sum_subarray_mins(arr: Vec<i32>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let n = arr.len();
        let mut stack = Vec::new();
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        
        // หาขอบเขตซ้าย
        for i in 0..n {
            while let Some(&top) = stack.last() {
                if arr[top] >= arr[i] {
                    stack.pop();
                } else {
                    break;
                }
            }
            left[i] = if stack.is_empty() { -1 } else { *stack.last().unwrap() as i32 };
            stack.push(i);
        }
        
        stack.clear();
        
        // หาขอบเขตขวา
        for i in (0..n).rev() {
            while let Some(&top) = stack.last() {
                if arr[top] > arr[i] {
                    stack.pop();
                } else {
                    break;
                }
            }
            right[i] = if stack.is_empty() { n as i32 } else { *stack.last().unwrap() as i32 };
            stack.push(i);
        }
        
        // คำนวณผลรวม
        let mut total: i64 = 0;
        for i in 0..n {
            let count = (i as i64 - left[i] as i64) * (right[i] as i64 - i as i64);
            total = (total + (count % MOD) * (arr[i] as i64)) % MOD;
        }
        
        total as i32
    }
}