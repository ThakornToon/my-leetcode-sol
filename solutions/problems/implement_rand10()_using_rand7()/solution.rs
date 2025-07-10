/** 
 * The rand7() API is already defined for you.
 * @return a random integer in the range 1 to 7
 * fn rand7() -> i32;
 */

impl Solution {
    pub fn rand10() -> i32 {
        loop {
            let mut num = (rand7() - 1) * 7 + rand7();  // 1-49
            if num <= 40 {
                return num % 10 + 1;
            }
            // ใช้ส่วนที่เหลือ (41-49) เพื่อลดการสุ่มซ้ำ -> rand 1-9
            num = (num - 40 - 1) * 7 + rand7();  // 1-63
            if num <= 60 {
                return num % 10 + 1;
            }
            // ใช้ส่วนที่เหลืออีกครั้ง (61-63)
            num = (num - 60 - 1) * 7 + rand7();  // 1-21
            if num <= 20 {
                return num % 10 + 1;
            }
        }
    }
}