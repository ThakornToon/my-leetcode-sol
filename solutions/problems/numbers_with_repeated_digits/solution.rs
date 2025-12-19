impl Solution {
    pub fn num_dup_digits_at_most_n(n: i32) -> i32 {
        let n = n as usize;
        // แยกตัวเลข
        let mut digits = Vec::new();
        let mut temp = n;
        while temp > 0 {
            digits.push(temp % 10);
            temp /= 10;
        }
        digits.reverse();
        let len = digits.len();
        
        // จำนวนที่ไม่มีตัวเลขซ้ำ
        let mut unique_count = 0;
        
        // 1. จำนวนที่มีหลักน้อยกว่า len
        for i in 1..len {
            unique_count += 9 * Self::permutation(9, i as i32 - 1);
        }
        
        // 2. จำนวนที่มี len หลัก และ ≤ n
        let mut used = [false; 10];
        let mut valid_prefix = true;
        
        for i in 0..len {
            let current_digit = digits[i];
            let start = if i == 0 { 1 } else { 0 };
            
            // สำหรับแต่ละหลักที่น้อยกว่า current_digit
            for d in start..current_digit {
                if !used[d] {
                    unique_count += Self::permutation(9 - i as i32, (len - i - 1) as i32);
                }
            }
            
            // ถ้า current_digit ใช้ไปแล้ว break
            if used[current_digit] {
                valid_prefix = false;
                break;
            }
            used[current_digit] = true;
        }
        
        // ถ้าทุกหลักของ n ไม่ซ้ำกัน
        if valid_prefix {
            unique_count += 1;
        }
        
        n as i32 - unique_count as i32
    }
    
    // P(n, k) = n!/(n-k)!
    fn permutation(n: i32, k: i32) -> i32 {
        if k <= 0 {
            return 1;
        }
        let mut result = 1;
        for i in 0..k {
            result *= n - i;
        }
        result
    }
}