impl Solution {
    pub fn min_flips(a: i32, b: i32, c: i32) -> i32 {
        let mut flips = 0;
        let mut a = a;
        let mut b = b;
        let mut c = c;
        
        while a > 0 || b > 0 || c > 0 {
            let bit_a = a & 1;
            let bit_b = b & 1;
            let bit_c = c & 1;
            
            if (bit_a | bit_b) != bit_c {
                if bit_c == 1 {
                    flips += 1;
                } else {
                    flips += bit_a + bit_b;
                }
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        flips
    }
}