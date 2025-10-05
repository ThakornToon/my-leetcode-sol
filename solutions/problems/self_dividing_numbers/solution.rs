impl Solution {
    pub fn self_dividing_numbers(left: i32, right: i32) -> Vec<i32> {
        (left..=right)
            .filter(|&num| Self::is_self_dividing(num))
            .collect()
    }
    
    fn is_self_dividing(num: i32) -> bool {
        let mut n = num;
        while n > 0 {
            let digit = n % 10;
            if digit == 0 || num % digit != 0 {
                return false;
            }
            n /= 10;
        }
        true
    }

}