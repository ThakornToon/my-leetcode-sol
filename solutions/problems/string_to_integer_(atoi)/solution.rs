impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let s = s.trim_start(); //ตัด white space ด้านหน้า
        if s.is_empty() {
            return 0;
        }
        let mut c = s.chars();
        let mut sign = 1;
        let mut result: i32 = 0;
        let c_sign = c.next().unwrap();
        if c_sign =='-' {
            sign = -1;
        }
        else if c_sign == '+' {
            sign = 1;
        }
        else {
            c = s.chars();
        }
        for letters in c {
            if !letters.is_digit(10) { //ดูว่าอักขระเป็นตัวเลขฐาน 10 ไหม
                break;
            }
            let digit: i32 = letters.to_digit(10).unwrap() as i32; //แปลงอักขระเป็นเลขฐาน 10 (คืนค่าเป็น u32)
            if result > (i32::MAX - digit) / 10 {
                return if sign == 1 { i32::MAX } else { i32::MIN };
            }
            result = result * 10 + digit;
            
        }
        return result*sign;
    }
}