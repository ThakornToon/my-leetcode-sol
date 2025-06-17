impl Solution {
    fn gcd(a: i32, b: i32) -> i32 {
        if b == 0 { a } else { Self::gcd(b, a % b) }
    }

    pub fn can_measure_water(x: i32, y: i32, target: i32) -> bool {
        if target > x + y {
            return false;
        }
        target % Self::gcd(x, y) == 0
    }
}