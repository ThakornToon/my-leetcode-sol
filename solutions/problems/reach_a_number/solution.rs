impl Solution {
    pub fn reach_number(target: i32) -> i32 {
        let target = target.abs();
        
        // หา n ขั้นต่ำที่ n(n+1)/2 >= target
        let mut n = ((((1 + 8 * target as i64) as f64).sqrt() - 1.0) / 2.0).ceil() as i32;
        let mut total = (n as i64 * (n as i64 + 1)) / 2;
        
        while (total - target as i64) % 2 != 0 {
            n += 1;
            total += n as i64;
        }
        
        n
    }
}