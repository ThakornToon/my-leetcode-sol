impl Solution {
    pub fn find_lex_smallest_string(s: String, a: i32, b: i32) -> String {
        let n = s.len();
        let a = a as usize;
        let b = b as usize;
        
        // Helper: หา greatest common divisor
        fn gcd(x: usize, y: usize) -> usize {
            if y == 0 { x } else { gcd(y, x % y) }
        }
        
        // จำนวนครั้งที่ต้องลอง add (cycle length ของ modulo 10)
        let add_limit = 10 / gcd(10, a);
        
        // จำนวนครั้งที่ต้องลอง rotate (ทุกๆ iInc ตำแหน่ง)
        let rotate_step = gcd(n, b);
        
        // b เป็นเลขคี่หรือไม่? (ถ้าคี่ สามารถ add ที่ตำแหน่งคู่ได้)
        let can_add_even = b % 2 == 1;
        
        // ขยายสตริงเพื่อให้ substr ง่าย (ทำเป็นวงกลม)
        let double_s = s.repeat(2);
        let chars: Vec<char> = double_s.chars().collect();
        
        // ฟังก์ชัน: ทำให้ตัวเลขในตำแหน่งที่กำหนด น้อยที่สุด โดยการบวก a ซ้ำๆ
        let minimize_digits = |str_chars: &mut Vec<char>, start_pos: usize| {
            // ค่าเดิมของตัวแรกในกลุ่มนี้
            let original_digit = str_chars[start_pos].to_digit(10).unwrap() as usize;
            
            // หาจำนวนครั้งที่บวก แล้วได้ digit น้อยที่สุด
            let mut min_digit = 10;
            let mut best_add_count = 0;
            
            for add_count in 0..add_limit {
                let new_digit = (original_digit + add_count * a) % 10;
                if new_digit < min_digit {
                    min_digit = new_digit;
                    best_add_count = add_count;
                }
            }
            
            // นำ digit ใหม่ไปใช้กับทุกตำแหน่งในกลุ่มนี้
            for i in (start_pos..str_chars.len()).step_by(2) {
                let digit = str_chars[i].to_digit(10).unwrap() as usize;
                let new_digit = (digit + best_add_count * a) % 10;
                str_chars[i] = char::from_digit(new_digit as u32, 10).unwrap();
            }
        };
        
        let mut best_result = s.clone();
        
        // ลองทุก rotation ที่เป็นไปได้
        for start in (0..n).step_by(rotate_step) {
            // ตัดสตริงความยาว n เริ่มที่ตำแหน่ง start
            let mut current: Vec<char> = chars[start..start + n].to_vec();
            
            // Step 1: ทำให้ตัวเลขที่ตำแหน่งคี่ (index 1,3,5,...) น้อยที่สุด
            minimize_digits(&mut current, 1);
            
            // Step 2: ถ้า b เป็นเลขคี่ สามารถทำให้ตำแหน่งคู่น้อยที่สุดได้ด้วย
            if can_add_even {
                minimize_digits(&mut current, 0);
            }
            
            // แปลงกลับเป็น String และเปรียบเทียบ
            let current_str: String = current.into_iter().collect();
            if current_str < best_result {
                best_result = current_str;
            }
        }
        
        best_result
    }
}