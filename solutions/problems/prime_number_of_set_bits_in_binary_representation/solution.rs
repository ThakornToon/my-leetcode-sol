impl Solution {
    pub fn count_prime_set_bits(left: i32, right: i32) -> i32 {
        // จำนวนเฉพาะที่ ≤ 20
        let primes = [false, false, true, true, false, true, 
                     false, true, false, false, false, true,
                     false, true, false, false, false, true,
                     false, true, false];
        
        let mut count = 0;
        
        for num in left..=right {
            // นับจำนวน bit 1
            let bits = num.count_ones() as usize;
            
            // ตรวจสอบว่าเป็นจำนวนเฉพาะ
            if primes[bits] {
                count += 1;
            }
        }
        
        count
    }
}