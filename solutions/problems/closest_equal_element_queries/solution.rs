use std::collections::HashMap;

impl Solution {
    pub fn solve_queries(nums: Vec<i32>, queries: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut pos_map: HashMap<i32, Vec<usize>> = HashMap::new();
        
        // เก็บตำแหน่งของแต่ละค่า
        for (i, &val) in nums.iter().enumerate() {
            pos_map.entry(val).or_insert(Vec::new()).push(i);
        }
        
        let mut result = Vec::new();
        
        for &q in &queries {
            let q = q as usize;
            let val = nums[q];
            let positions = pos_map.get(&val).unwrap();
            let m = positions.len();
            
            if m <= 1 {
                result.push(-1);
                continue;
            }
            
            // binary search หาตำแหน่ง q
            match positions.binary_search(&q) {
                Ok(pos) => {
                    let mut min_dist = i32::MAX;
                    
                    // ตัวก่อนหน้า (ใน array ปกติ)
                    if pos > 0 {
                        let dist = (q - positions[pos - 1]) as i32;
                        min_dist = min_dist.min(dist);
                    } else {
                        // ถ้าเป็นตัวแรก ให้พิจารณาตัวสุดท้ายแบบ circular
                        let dist = (q + n - positions[m - 1]) as i32;
                        min_dist = min_dist.min(dist);
                    }
                    
                    // ตัวถัดไป (ใน array ปกติ)
                    if pos < m - 1 {
                        let dist = (positions[pos + 1] - q) as i32;
                        min_dist = min_dist.min(dist);
                    } else {
                        // ถ้าเป็นตัวสุดท้าย ให้พิจารณาตัวแรกแบบ circular
                        let dist = (positions[0] + n - q) as i32;
                        min_dist = min_dist.min(dist);
                    }
                    
                    result.push(min_dist);
                }
                Err(_) => result.push(-1),
            }
        }
        
        result
    }
}