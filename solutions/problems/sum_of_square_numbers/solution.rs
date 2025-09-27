impl Solution {
    pub fn judge_square_sum(c: i32) -> bool {
        let c = c as i64;
        let mut left: i64 = 0;
        let mut right: i64 = (c as f64).sqrt() as i64;
        
        while left <= right {
            let sum = left * left + right * right;
            if sum == c {
                return true;
            } else if sum < c {
                left += 1;
            } else {
                right -= 1;
            }
        }
        
        false
    }
}