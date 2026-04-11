use std::collections::HashMap;

impl Solution {
    pub fn minimum_distance(nums: Vec<i32>) -> i32 {
        let mut positions: HashMap<i32, Vec<usize>> = HashMap::new();
        
        // เก็บตำแหน่งของแต่ละค่า
        for (i, &val) in nums.iter().enumerate() {
            positions.entry(val).or_insert(Vec::new()).push(i);
        }
        
        let mut min_dist = i32::MAX;
        
        // สำหรับแต่ละค่าที่มีอย่างน้อย 3 ตัว
        for pos in positions.values() {
            let m = pos.len();
            if m < 3 { continue; }
            
            // ระยะทาง = 2*(pos[c] - pos[a]) สำหรับ a < b < c
            // ต้องการ a และ c ที่ใกล้กันที่สุด
            for a in 0..m - 2 {
                let c = a + 2;
                let dist = 2 * (pos[c] - pos[a]) as i32;
                min_dist = min_dist.min(dist);
            }
        }
        
        if min_dist == i32::MAX { -1 } else { min_dist }
    }
}