impl Solution {
    pub fn single_number(nums: Vec<i32>) -> Vec<i32> {
        let mut mask = 0;

        for &val in &nums {
            mask ^= val;
        }

        mask &= -mask;

        let mut val1 = 0;
        let mut val2 = 0;

        for &val in &nums {
            if val & mask == 0 {
                val1 ^= val;
            } else {
                val2 ^= val;
            }
        }

        return vec![val1, val2];
    
    }
}