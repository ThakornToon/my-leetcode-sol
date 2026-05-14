use std::collections::VecDeque;
use std::collections::HashMap;

impl Solution {

    pub fn min_days(n: i32) -> i32 {
        let mut queue = VecDeque::new();
        let mut dist = HashMap::new();  // เก็บระยะทาง (จำนวนวัน) จากจุดเริ่มต้นไปยังแต่ละค่า
        
        queue.push_back(n);
        dist.insert(n, 0);
        
        while let Some(curr) = queue.pop_front() {
            // เจอวิธีกินจนหมดที่สั้นสุด
            if curr == 0 {
                return dist[&curr];
            }
            
            let next_days = dist[&curr] + 1;
            
            // ลดทีละ 1
            if !dist.contains_key(&(curr - 1)) {
                dist.insert(curr - 1, next_days);
                queue.push_back(curr - 1);
            }
            
            // ถ้า n % 2 == 0 และยังไม่ถูกคิด
            if curr % 2 == 0 && !dist.contains_key(&(curr / 2)) {
                dist.insert(curr / 2, next_days);
                queue.push_back(curr / 2);
            }
            
            // ถ้า n % 3 == 0 และยังไม่ถูกคิด
            if curr % 3 == 0 && !dist.contains_key(&(curr / 3)) {
                dist.insert(curr / 3, next_days);
                queue.push_back(curr / 3);
            }
        }
        
        -1
    }
}