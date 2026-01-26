impl Solution {
    pub fn max_length(arr: Vec<String>) -> i32 {
        let mut masks = Vec::new();
        let mut lengths = Vec::new();
        
        // แปลงสตริงเป็น masks
        for s in &arr {
            let mut mask = 0u32;
            let mut valid = true;
            
            for c in s.chars() {
                let bit = 1 << (c as u8 - b'a');
                
                // ตรวจสอบตัวอักษรซ้ำ
                if mask & bit != 0 {
                    valid = false;
                    break;
                }
                
                mask |= bit;
            }
            
            if valid {
                masks.push(mask);
                lengths.push(s.len() as i32);
            }
        }
        
        let mut max_len = 0;
        Self::backtrack(&masks, &lengths, 0, 0, 0, &mut max_len);
        
        max_len
    }
    
    fn backtrack(masks: &[u32], lengths: &[i32], 
                 index: usize, current_mask: u32, 
                 current_length: i32, max_len: &mut i32) {
        // อัปเดตค่าสูงสุด
        if current_length > *max_len {
            *max_len = current_length;
        }
        
        // ฐาน: ตรวจสอบครบทุกสตริงแล้ว
        if index == masks.len() {
            return;
        }
        
        // 1. ไม่เลือกสตริงนี้
        Self::backtrack(masks, lengths, index + 1, 
                       current_mask, current_length, max_len);
        
        // 2. เลือกสตริงนี้ (ถ้าไม่ชนกับ masks ที่มีอยู่)
        if current_mask & masks[index] == 0 {
            Self::backtrack(masks, lengths, index + 1,
                          current_mask | masks[index],
                          current_length + lengths[index],
                          max_len);
        }
    }
}