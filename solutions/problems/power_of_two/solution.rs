impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        if n <= 0 {
            return false;
        }
        let log = (n as f64).log2();
        return log == log.round();
    }
}