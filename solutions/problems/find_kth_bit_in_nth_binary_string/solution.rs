impl Solution {
    pub fn find_kth_bit(n: i32, k: i32) -> char {
        let mut n = n;
        let mut k = k;
        let mut invert = false;
        
        while n > 1 {
            let length = (1 << n) - 1;
            let mid = length / 2 + 1;
            
            if k == mid {
                return if invert { '0' } else { '1' };
            }
            else if k > mid {
                k = length - k + 1;
                invert = !invert;
            }
            // ถ้า k < mid: อยู่ในส่วนแรก
            
            n -= 1;
        }
        
        // n == 1
        if invert { '1' } else { '0' }
    }
}