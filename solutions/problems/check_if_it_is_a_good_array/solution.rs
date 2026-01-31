impl Solution {
    pub fn is_good_array(nums: Vec<i32>) -> bool {
        let mut result = nums[0];
        for &num in nums.iter().skip(1) {
            result = Self::gcd(result, num);
            if result == 1 {
                return true;
            }
        }
        
        result == 1
    }

    fn gcd(a: i32, b: i32) -> i32 {
        if b == 0 {
            a
        } else {
            Self::gcd(b, a % b)
        }
    }
}