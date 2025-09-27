impl Solution {
    pub fn find_integers(n: i32) -> i32 {
        if n < 2 {
            return n + 1;
        }
        
        // Fibonacci sequence
        let mut fib = vec![0; 32];
        fib[0] = 1;
        fib[1] = 2;
        
        for i in 2..32 {
            fib[i] = fib[i-1] + fib[i-2];
        }
        
        let mut result = 0;
        let mut prev_bit = 0;
        
        // ตรวจสอบจากบิตสูงสุดไปต่ำสุด (30 คือบิตสูงสุดสำหรับ i32)
        for i in (0..=30).rev() {
            let bit = (n >> i) & 1;
            
            if bit == 1 {
                result += fib[i as usize];
                
                if prev_bit == 1 {
                    return result;  // พบ 11 → หยุดนับ
                }
                prev_bit = 1;
            } else {
                prev_bit = 0;
            }
        }
        
        result + 1  // บวกตัว n เอง
    }
}