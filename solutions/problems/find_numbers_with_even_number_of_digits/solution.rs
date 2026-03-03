impl Solution {
    pub fn find_numbers(nums: Vec<i32>) -> i32 {
        let mut count = 0;
        
        for &num in &nums {
            let mut temp = num;
            let mut digits = 0;
            
            while temp > 0 {
                digits += 1;
                temp /= 10;
            }
            
            if digits % 2 == 0 {
                count += 1;
            }
        }
        
        count
    }
}