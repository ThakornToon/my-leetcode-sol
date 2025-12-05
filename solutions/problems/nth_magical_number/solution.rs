impl Solution {
    pub fn nth_magical_number(n: i32, a: i32, b: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        
        let (a, b, n) = (a as i64, b as i64, n as i64);
        
        // หา LCM
        let lcm: i64 = a * b / Self::gcd(a, b);
        
        let mut low: i64 = a.min(b);
        let mut high: i64 = n * low;
        
        while low < high {
            let mid: i64 = low + (high - low) / 2;
            
            let count: i64 = mid / a + mid / b - mid / lcm;
            
            if count < n {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        (low % MOD) as i32
    }

    fn gcd(mut a: i64, mut b: i64) -> i64 {
        while b != 0 {
            let temp = b;
            b = a % b;
            a = temp;
        }
        a
    }
}