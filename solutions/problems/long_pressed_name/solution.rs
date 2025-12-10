impl Solution {
    pub fn is_long_pressed_name(name: String, typed: String) -> bool {
        let name_len = name.len();
        let typed_len = typed.len();
        
        // ถ้า typed สั้นกว่า name เป็นไปไม่ได้
        if typed_len < name_len {
            return false;
        }
        
        let name_bytes = name.as_bytes();
        let typed_bytes = typed.as_bytes();
        
        let mut i = 0;
        let mut j = 0;
        
        while i < name_len && j < typed_len {
            // นับจำนวนตัวอักษรที่ติดกันใน name
            let current = name_bytes[i];
            let mut name_count = 0;
            while i < name_len && name_bytes[i] == current {
                name_count += 1;
                i += 1;
            }
            
            // นับจำนวนตัวอักษรที่ติดกันใน typed
            let mut typed_count = 0;
            while j < typed_len && typed_bytes[j] == current {
                typed_count += 1;
                j += 1;
            }
            
            // จำนวนใน typed ต้อง >= ใน name
            if typed_count < name_count {
                return false;
            }
        }
        
        // ตรวจสอบว่าทั้ง name และ typed จบพร้อมกัน
        i == name_len && j == typed_len
    }
}