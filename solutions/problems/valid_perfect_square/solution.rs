impl Solution {
    pub fn is_perfect_square(num: i32) -> bool {
        let num: i64 = num as i64;
        let mut l: i64 = 1;
        let mut r: i64 = (num / 2 + 1) as i64;
        while l <= r {
            let m: i64 = l + (r - l) / 2;
            if (m*m == num) {
                return true;
            } else if (m * m < num) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return false;
    }
}