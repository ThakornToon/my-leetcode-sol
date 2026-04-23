impl Solution {
    pub fn find_min_fibonacci_numbers(k: i32) -> i32 {
        let mut fib = vec![1, 1];
        
        // สร้าง Fibonacci numbers จนเกิน k
        while *fib.last().unwrap() <= k {
            let next = fib[fib.len() - 1] + fib[fib.len() - 2];
            fib.push(next);
        }
        
        let mut result = 0;
        let mut remaining = k;
        
        // เลือกจากมากไปน้อย
        for &num in fib.iter().rev() {
            if num <= remaining {
                remaining -= num;
                result += 1;
            }
        }
        
        result
    }
}