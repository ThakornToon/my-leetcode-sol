impl Solution {
    pub fn mirror_reflection(p: i32, q: i32) -> i32 {
        fn gcd(mut a: i32, mut b: i32) -> i32 {
            while b != 0 {
                let temp = a % b;
                a = b;
                b = temp;
            }
            a
        }
        
        let g = gcd(p, q);
        let p = p / g;
        let q = q / g;
        
        if p % 2 == 0 {
            2
        } else if q % 2 == 0 {
            0
        } else {
            1
        }
    }
}