impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let m = strs.len();
        let n = strs[0].len();
        let mut deletions = 0;
        
        // สร้าง array สำหรับเก็บสถานะการเรียงลำดับ
        let mut decided = vec![false; m - 1];
        let mut decided_count = 0;
        
        for col in 0..n {
            if decided_count == m - 1 {
                break; // ทุกคู่ตัดสินแล้ว
            }
            
            let mut valid = true;
            
            // ตรวจสอบว่าต้องลบหรือไม่
            for row in 1..m {
                if !decided[row - 1] {
                    let current_char = strs[row].as_bytes()[col];
                    let prev_char = strs[row - 1].as_bytes()[col];
                    
                    if current_char < prev_char {
                        valid = false;
                        break;
                    }
                }
            }
            
            if !valid {
                deletions += 1;
            } else {
                // อัปเดต decided สำหรับคู่ที่ตัดสินแล้ว
                for row in 1..m {
                    if !decided[row - 1] {
                        let current_char = strs[row].as_bytes()[col];
                        let prev_char = strs[row - 1].as_bytes()[col];
                        
                        if current_char > prev_char {
                            decided[row - 1] = true;
                            decided_count += 1;
                        }
                    }
                }
            }
        }
        
        deletions
    }
}