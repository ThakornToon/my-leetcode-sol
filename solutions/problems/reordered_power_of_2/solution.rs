impl Solution {
    pub fn reordered_power_of2(n: i32) -> bool {
        // ฟังก์ชันนับจำนวนครั้งของแต่ละเลข
        fn count_digits(mut num: i32) -> [u8; 10] {
            let mut count = [0u8; 10];
            while num > 0 {
                count[(num % 10) as usize] += 1;
                num /= 10;
            }
            count
        }
        
        let n_count = count_digits(n);
        
        // ตรวจสอบทุก power of 2 ที่อยู่ใน range
        let mut power = 1i32;
        for _ in 0..31 { 
            let power_count = count_digits(power);
            
            if n_count == power_count {
                return true;
            }
            
            power <<= 1;  // คูณ 2
        }
        
        false
    }
}