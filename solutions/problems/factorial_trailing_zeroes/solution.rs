impl Solution {
    pub fn trailing_zeroes(n: i32) -> i32 {
        let mut count = 0;
        let mut i = 5;
        while i <= n {
            count += n / i;
            i *= 5
        }
        return count;
    }
}