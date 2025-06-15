impl Solution {
    pub fn hamming_weight(n: i32) -> i32 {
        let mut res = 0;
        for i in 0..32 {
            if ((n >> i) & 1) == 1 {
                res += 1;
            }
        }
        res
    }
}