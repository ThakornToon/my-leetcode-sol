impl Solution {
    pub fn sum_four_divisors(nums: Vec<i32>) -> i32 {
        let mut total = 0;
        
        for &num in &nums {
            let mut first_divisor = 0;
            let sqrt_num = (num as f64).sqrt() as i32;
            
            for d in 2..=sqrt_num {
                if num % d == 0 {
                    if first_divisor == 0 {
                        first_divisor = d;
                    } else {
                        // มีตัวหารมากกว่า 1 คู่
                        first_divisor = -1;
                        break;
                    }
                }
            }
            
            if first_divisor > 0 && first_divisor != num / first_divisor {
                total += 1 + num + first_divisor + (num / first_divisor);
            }
        }
        
        total
    }
}