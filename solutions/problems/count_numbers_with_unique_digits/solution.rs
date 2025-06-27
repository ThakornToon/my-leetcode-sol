impl Solution {
    pub fn count_numbers_with_unique_digits(n: i32) -> i32 {
        if (n == 0) {
            return 1;
        }
        let mut total = 10; // สำหรับ 1 หลัก
        let mut uniqueDigits = 9;
        let mut availableNumbers = 9;
        
        for i in 2..=n {
            uniqueDigits *= availableNumbers;
            total += uniqueDigits;
            availableNumbers -= 1;
        }
        
        return total;
    }
}