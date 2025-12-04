impl Solution {
    pub fn prime_palindrome(n: i32) -> i32 {
        let n = n as i64;
        
        // กรณีพิเศษ
        if n <= 2 { return 2; }
        if n <= 3 { return 3; }
        if n <= 5 { return 5; }
        if n <= 7 { return 7; }
        if n <= 11 { return 11; }
        
        // ฟังก์ชันตรวจสอบ prime
        fn is_prime(num: i64) -> bool {
            if num < 2 { return false; }
            if num == 2 { return true; }
            if num % 2 == 0 { return false; }
            
            let limit = (num as f64).sqrt() as i64;
            for i in (3..=limit).step_by(2) {
                if num % i == 0 {
                    return false;
                }
            }
            true
        }
        
        // Generate palindrome จำนวนหลักคี่ (3, 5, 7, 9 หลัก)
        for length in 2..=5 {  // ครึ่งความยาว
            // ค่าสูงสุดของครึ่งแรก
            let half_max = 10i64.pow(length);
            let half_min = 10i64.pow(length - 1);
            
            // สร้าง palindrome จากครึ่งแรก
            for half in half_min..half_max {
                // สร้าง string จากครึ่งแรก
                let half_str = half.to_string();
                
                // สร้าง palindrome จำนวนหลักคี่
                let mut palindrome_str = half_str.clone();
                // เพิ่มส่วนกลับของครึ่งแรก (ไม่รวมตัวสุดท้าย)
                for ch in half_str.chars().rev().skip(1) {
                    palindrome_str.push(ch);
                }
                
                // แปลงเป็นตัวเลข
                let palindrome = palindrome_str.parse::<i64>().unwrap();
                
                // ตรวจสอบว่า >= n และเป็น prime
                if palindrome >= n && is_prime(palindrome) {
                    return palindrome as i32;
                }
            }
        }
        return -1;
    }
}