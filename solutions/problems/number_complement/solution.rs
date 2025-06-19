impl Solution {
    pub fn find_complement(num: i32) -> i32 {
        if num == 0 {
            return 1;
        }
        
        let mut mask = 1;
        while mask <= num && mask > 0 {  // ตรวจสอบว่า mask ไม่ overflow
            mask <<= 1;
        }
        
        if mask < 0 {  // กรณี overflow ให้ใช้ค่าสูงสุด
            mask = i32::MAX;
        } else {
            mask -= 1;
        }
        
        num ^ mask
    }
}