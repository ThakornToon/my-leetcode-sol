impl Solution {
    pub fn arrange_coins(n: i32) -> i32 {
        ((2.0 * n as f64 + 0.25).sqrt() - 0.5) as i32
    }
}