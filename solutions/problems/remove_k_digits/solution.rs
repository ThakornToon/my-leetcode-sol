impl Solution {
    pub fn remove_kdigits(num: String, k: i32) -> String {
        let mut k = k as usize;  
        let mut stack = Vec::new(); 
        
        for digit in num.chars() {
            while k > 0 && !stack.is_empty() && stack.last().unwrap() > &digit {
                stack.pop();  
                k -= 1;       
            }
            stack.push(digit);  
        }
        while k > 0 {
            stack.pop();
            k -= 1;
        }
        let result: String = stack.into_iter().collect();
        let trimmed_result = result.trim_start_matches('0'); // ลบตัวอักษร '0' ทั้งหมดที่อยู่ด้านหน้าสตริง คืนค่าเป็น string slice (&str) ที่ชี้ไปยังข้อมูลเดิม ไม่ได้ allocate memory ใหม่

        if trimmed_result.is_empty() {
            "0".to_string()
        } else {
            trimmed_result.to_string()
        }
    }
}