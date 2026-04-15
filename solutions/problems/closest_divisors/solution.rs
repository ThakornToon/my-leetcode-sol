impl Solution {
    pub fn closest_divisors(num: i32) -> Vec<i32> {
        fn find_divisors(n: i32) -> (i32, i32) {
            let sqrt_n = (n as f64).sqrt() as i32;
            for a in (1..=sqrt_n).rev() {
                if n % a == 0 {
                    return (a, n / a);
                }
            }
            (1, n)
        }
        
        let (a1, b1) = find_divisors(num + 1);
        let (a2, b2) = find_divisors(num + 2);
        
        if b1 - a1 < b2 - a2 {
            vec![a1, b1]
        } else {
            vec![a2, b2]
        }
    }
}