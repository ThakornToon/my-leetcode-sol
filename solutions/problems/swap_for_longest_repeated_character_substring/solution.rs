impl Solution {
    pub fn max_rep_opt1(text: String) -> i32 {
        let chars: Vec<char> = text.chars().collect();
        let mut count = [0; 26];
        
        // นับจำนวนตัวอักษรทั้งหมด
        for &c in &chars {
            count[c as usize - 'a' as usize] += 1;
        }
        
        let mut max_len = 0;
        let mut i = 0;
        
        while i < chars.len() {
            let mut j = i;
            // หาความยาวกลุ่มปัจจุบัน
            while j < chars.len() && chars[j] == chars[i] {
                j += 1;
            }
            
            let cur_len = j - i;
            let cur_char = chars[i];
            let idx = cur_char as usize - 'a' as usize;

            // กรณี 1: เพิ่ม 1 ตัวจากกลุ่มอื่น
            max_len = max_len.max(if count[idx] > cur_len { cur_len + 1 } else { cur_len });
            
            // กรณี 2: ตรวจสอบการรวมกลุ่ม
            // ดูว่ามีตัวอักษรอื่นคั่น 1 ตัวหรือไม่
            if j + 1 < chars.len() && chars[j + 1] == cur_char {
                let mut k = j + 1;
                // หาความยาวกลุ่มถัดไป
                while k < chars.len() && chars[k] == cur_char {
                    k += 1;
                }
                
                let next_len = k - (j + 1);
                let combined = cur_len + next_len;
                
                // มีช่องว่าง 1 ตัวตรงกลาง (ที่ตำแหน่ง j)
                max_len = max_len.max(if count[idx] > combined { combined + 1 } else { combined });
            }
            
            i = j;
        }
        
        max_len as i32
    }
}