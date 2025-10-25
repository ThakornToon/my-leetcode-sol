/*
n = a + (a+1) + (a+2) + ... + (a+k-1) ; k พจน์

ซึ่งสามารถเขียนเป็น:
n = k*a + (0 + 1 + 2 + ... + k-1)
n = k*a + k*(k-1)/2

จัดรูปใหม่ได้:
k*a = n - k*(k-1)/2

เงื่อนไข:
n - k*(k-1)/2 > 0 (ต้องเป็นจำนวนบวก)
(n - k*(k-1)/2) % k == 0 (ต้องหาร k ลงตัว จะได้ k, a เป็นจำนวนเต็มทั้งคู่)
*/

impl Solution {
    pub fn consecutive_numbers_sum(n: i32) -> i32 {
        let mut count = 0;
        let mut k = 1;
        
        loop {
            let temp = n - k * (k - 1) / 2;
            if temp <= 0 {
                break;
            }
            
            if temp % k == 0 {
                count += 1;
            }
            
            k += 1;
        }
        
        count
    }
}