impl Solution {
    pub fn separate_digits(nums: Vec<i32>) -> Vec<i32> {
        let mut result = Vec::new();
        
        for mut num in nums {
            if num == 0 {
                result.push(0);
                continue;
            }
            
            let mut digits = Vec::new();
            while num > 0 {
                digits.push(num % 10);
                num /= 10;
            }
            digits.reverse();
            result.extend(digits);
        }
        
        result
    }
}