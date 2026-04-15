impl Solution {
    pub fn largest_multiple_of_three(digits: Vec<i32>) -> String {
        let mut digits = digits;
        // เรียงจากมากไปน้อย
        digits.sort_unstable_by(|a, b| b.cmp(a));
        
        let sum: i32 = digits.iter().sum();
        let mut count = [0; 10];
        
        for &d in &digits {
            count[d as usize] += 1;
        }
        
        let remainder = (sum % 3) as usize;
        
        if remainder != 0 {
            let mut removed = false;
            
            // ลบ digit ที่มี remainder = remainder (ตัวเล็กสุด)
            for i in (remainder..=9).step_by(3) {
                if count[i] > 0 {
                    count[i] -= 1;
                    removed = true;
                    break;
                }
            }
            
            // ถ้ายังไม่ถูกลบ ให้ลบ 2 ตัว
            if !removed {
                let target = 3 - remainder;
                let mut removed_count = 0;
                for i in (target..=9).step_by(3) {
                    while count[i] > 0 && removed_count < 2 {
                        count[i] -= 1;
                        removed_count += 1;
                    }
                    if removed_count == 2 { break; }
                }
            }
        }
        
        // สร้างผลลัพธ์
        let mut result = String::new();
        for i in (0..=9).rev() {
            result.push_str(&format!("{}", i.to_string().repeat(count[i])));
        }
        
        // กรณีพิเศษ
        if result.is_empty() {
            return String::new();
        }
        if result.starts_with('0') {
            return "0".to_string();
        }
        
        result
    }
}