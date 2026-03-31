impl Solution {
    pub fn number_of_steps(num: i32) -> i32 {
        if num == 0 {
            return 0;
        }
        
        // นับจำนวน 1 bits
        let ones = num.count_ones() as i32;
        // นับจำนวน bits ทั้งหมด (position of highest bit)
        let bits = 32 - num.leading_zeros() as i32;
        
        ones + bits - 1
    }
}