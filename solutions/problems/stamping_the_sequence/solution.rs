impl Solution {
    pub fn moves_to_stamp(stamp: String, target: String) -> Vec<i32> {
        let m = stamp.len();
        let n = target.len();
        let stamp_bytes = stamp.as_bytes();
        let target_bytes = target.as_bytes();
        
        let mut result = Vec::new();
        let mut done = vec![false; n];
        let mut total_done = 0;
        
        while total_done < n {
            let mut found = false;
            
            for i in 0..=n - m {
                // ตรวจสอบว่า stamp match กับ target หรือไม่
                let mut match_possible = true;
                let mut new_changes = 0;
                
                for j in 0..m {
                    if !done[i + j] && target_bytes[i + j] != stamp_bytes[j] {
                        match_possible = false;
                        break;
                    }
                    if !done[i + j] {
                        new_changes += 1;
                    }
                }
                
                if match_possible && new_changes > 0 {
                    // Mark ตำแหน่งเหล่านี้ว่าเสร็จแล้ว
                    for j in 0..m {
                        if !done[i + j] {
                            done[i + j] = true;
                            total_done += 1;
                        }
                    }
                    
                    result.push(i as i32);
                    found = true;
                    break;
                }
            }
            
            if !found {
                return Vec::new();
            }
        }
        
        result.reverse();
        result
    }
}