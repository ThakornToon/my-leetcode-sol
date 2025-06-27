impl Solution {
    pub fn lexical_order(n: i32) -> Vec<i32> {
        let mut result = Vec::new();
        let mut current = 1;
        for _ in 1..=n {
            result.push(current);
            if current * 10 <= n {
                current *= 10;
            } else {
                while current % 10 == 9 || current + 1 > n {
                    current /= 10;
                }
                current += 1;
            }
        }
        return result;
    }
}