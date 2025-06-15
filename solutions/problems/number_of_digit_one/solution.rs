impl Solution {
    pub fn count_digit_one(n: i32) -> i32 {
        let mut count = 0;
        let mut lower = 0;
        let mut higher = n;
        let mut mul = 1;
        while higher > 0 {
            let curr = higher % 10;
            higher /= 10;

            if curr == 0 {
                count += higher * mul;
            } else if curr > 1 {
                count += (higher + 1) * mul;
            } else if curr == 1 {
                count += (higher * mul) + (lower + 1);
            }

            lower = lower + curr * mul;
            mul = mul.saturating_mul(10);
        }
        return count;
    }
}