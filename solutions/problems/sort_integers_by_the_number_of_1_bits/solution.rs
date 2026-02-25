impl Solution {
    pub fn sort_by_bits(arr: Vec<i32>) -> Vec<i32> {
        let mut arr = arr;
        arr.sort_by(|a, b| {
            let bits_a = a.count_ones();
            let bits_b = b.count_ones();
            
            if bits_a != bits_b {
                bits_a.cmp(&bits_b)
            } else {
                a.cmp(b)
            }
        });
        arr
    }
}