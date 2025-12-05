impl Solution {
    pub fn nth_ugly_number(n: i32, a: i32, b: i32, c: i32) -> i32 {
        let (n, a, b, c) = (n as i64, a as i64, b as i64, c as i64);
        
        let min_val = a.min(b.min(c));
        let mut left = 1;
        let mut right = n * min_val;
        
        while left < right {
            let mid = left + (right - left) / 2;
            
            if Self::count_ugly(mid, a, b, c) >= n {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        left as i32
    }

    fn gcd(mut a: i64, mut b: i64) -> i64 {
        while b != 0 {
            let temp = b;
            b = a % b;
            a = temp;
        }
        a
    }
    
    fn lcm(a: i64, b: i64) -> i64 {
        a / Self::gcd(a, b) * b
    }
    
    fn count_ugly(mid: i64, a: i64, b: i64, c: i64) -> i64 {
        let lab = Self::lcm(a, b);
        let lbc = Self::lcm(b, c);
        let lac = Self::lcm(a, c);
        let labc = Self::lcm(lab, c);
        
        mid / a + mid / b + mid / c
        - mid / lab - mid / lbc - mid / lac
        + mid / labc
    }
}