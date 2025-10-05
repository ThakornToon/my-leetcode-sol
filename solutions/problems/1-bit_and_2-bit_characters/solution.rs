impl Solution {
    pub fn is_one_bit_character(bits: Vec<i32>) -> bool {
        let n = bits.len();
        let mut i = 0;
        
        while i < n - 1 {
            if bits[i] == 1 {
                i += 2; // Skip 2-bit character
            } else {
                i += 1; // Skip 1-bit character
            }
        }
        
        i == n - 1
    }
}