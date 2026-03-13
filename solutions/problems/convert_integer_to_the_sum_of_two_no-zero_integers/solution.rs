impl Solution {
    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        let mut a = 1;
        loop {
            let b = n - a;
            if Self::is_valid(a) && Self::is_valid(b) {
                return vec![a, b];
            }
            a += 1;
        }
    }

    fn is_valid(mut num: i32) -> bool {
        while num > 0 {
            if num % 10 == 0 {
                return false;
            }
            num /= 10;
        }
        true
    }
}